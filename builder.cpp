#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define BRAZO 1
#define PIERNA 2

using namespace std;

class ojo{
    public:
        string color;
        double size;

        ojo(string c, double s){
            color = c;
            size = s;
        }
};

class oreja{
    public:
        string posicion;
        double size;

        oreja(string p, double s){
            posicion = p;
            size = s;
        }
};

class nariz{
    public:
        int orificios;
        double size;

        nariz(int o, double s){
            orificios = o;
            size = s;
        }
};

class boca{
    public:
        bool labios;
        string posicion;
        double size;

        boca(bool l, string p, double s){
            labios = l;
            posicion = p;
            size = s;
        }
};

class cabeza{
    public:
        vector<ojo> ojos;
        vector<oreja> orejas;
        vector<nariz> narices;
        vector<boca> bocas;
};

class extremidad{
    public:
        int tipo;
        int dedos;
        double size;

        extremidad(int t, int d, double s){
            tipo = t;
            dedos = d;
            size = s;
        }
};

class cuerpo{
    public:
        vector<cabeza> cabezas;
        vector<extremidad> extremidades;
        string pelo;

    cuerpo(){
        pelo = "pelo corto";
    }

    cuerpo(string p){
        pelo = p;
    }
        
};

class Creatura{
    public:
        string nombre;
        cuerpo cuerpoPrincipal;

        Creatura() {}

        Creatura(string p, string n){
            cuerpoPrincipal.pelo = p;
            nombre = n;
        }

        string obtenerDescripcion(){
            stringstream descripcion;
            descripcion << "Esta creatura se llama " + nombre
                        << " esta cubierta de " + cuerpoPrincipal.pelo
                        << " tiene " << cuerpoPrincipal.cabezas.size() << " cabezas"
                        << " y " << cuerpoPrincipal.extremidades.size() << " extremidades: \n";
            for(extremidad x : cuerpoPrincipal.extremidades)
                descripcion << ((x.tipo == BRAZO)?"un brazo":"una pierna ") << " con " << x.dedos << " dedos"
                            << " miden " << x.size << "cm.\n";

            int i = 0;
            for(cabeza c : cuerpoPrincipal.cabezas){
                descripcion << "La cabeza numero " << i << " y tiene: \n";
                for(ojo o : c.ojos)
                    descripcion << "un ojo de color " << o.color << " y mide "<< o.size << "cm.\n" ;

                for(oreja o : c.orejas)
                    descripcion << "una oreja esta en el" << o.posicion << " de la cabeza y mide "<< o.size << "cm.\n" ;

                for(nariz n : c.narices)
                    descripcion << "una nariz con " << n.orificios << " orificios y mide "<< n.size << "cm.\n" ;

                for(boca b : c.bocas)
                    descripcion << "una boca " << ((b.labios)?"con labios":"sin labios") << ", esta en el " << b.posicion << " y mide " << b.size << "cm.\n" ;

                i++;
            }

            return descripcion.str();

        }
};

class Builder{
    public:
        Creatura* creatura;

        Creatura* crearCreatura(string pelo, string nombre){
            creatura = new Creatura(pelo, nombre);
            return creatura;
        }

        Creatura* obtenerCreatura(){
            return creatura;
        }

        void agregarExtremidades(int tipo, int dedos, double size){
            creatura->cuerpoPrincipal.extremidades.push_back(extremidad(tipo, dedos, size));
        }

        void agregarCabezas(int cantidad){
            for (int i = 0; i < cantidad; i++)
                creatura->cuerpoPrincipal.cabezas.push_back(cabeza());
        }

        void agregarOjos(int iCabeza, int cantidad, string color, double size){
            if (iCabeza < creatura->cuerpoPrincipal.cabezas.size())
                for (int i = 0; i < cantidad; i++)
                    creatura->cuerpoPrincipal.cabezas[iCabeza].ojos.push_back(ojo(color, size));
        }

        void agregarOrejas(int iCabeza, int cantidad, string posicion, double size){
            if (iCabeza < creatura->cuerpoPrincipal.cabezas.size())
                for (int i = 0; i < cantidad; i++)
                    creatura->cuerpoPrincipal.cabezas[iCabeza].orejas.push_back(oreja(posicion, size));
        }

        void agregarNarices(int iCabeza, int cantidad, int orificios, double size){
            if (iCabeza < creatura->cuerpoPrincipal.cabezas.size())
                for (int i = 0; i < cantidad; i++)
                    creatura->cuerpoPrincipal.cabezas[iCabeza].narices.push_back(nariz(orificios, size));
        }

        void agregarBocas(int iCabeza, int cantidad, bool labios, string posicion, double size){
            if (iCabeza < creatura->cuerpoPrincipal.cabezas.size())
                for (int i = 0; i < cantidad; i++)
                    creatura->cuerpoPrincipal.cabezas[iCabeza].bocas.push_back(boca(labios, posicion, size));
        }

        ~Builder(){
            delete creatura;
        }
};

int main() {
    Builder builder;
    builder.crearCreatura("pelo corto", "Humano");
    builder.agregarExtremidades(BRAZO, 5, 70.0);
    builder.agregarExtremidades(BRAZO, 5, 70.0);
    builder.agregarExtremidades(PIERNA, 5, 70.0);
    builder.agregarExtremidades(PIERNA, 5, 70.0);
    builder.agregarCabezas(2);
    builder.agregarOjos(0, 2, "azul", 2.0);
    builder.agregarOrejas(0, 2, "lado", 5.0);
    builder.agregarNarices(0, 1, 2, 4.0);
    builder.agregarBocas(0, 1, true, "el centro", 5.0);

    cout << builder.obtenerCreatura()->cuerpoPrincipal.cabezas[0].ojos[0].color;

    cout << builder.obtenerCreatura()->obtenerDescripcion();
}
