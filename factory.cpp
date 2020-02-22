#include <iostream>
#include <string>
#include <vector>

using namespace std;

class piso {
    public: 
        double width, height;

    piso(){}

    piso(double w, double h){
        width = w;
        height = h;
    }
};

class techo{
    public:
        double height;
        string tipo;

    techo(double h, string t){
        height = h;
        tipo = t;
    }
};

class CasaNormal{
    public:
        piso* pisoPrincipal;
        techo* techoCasa;

    CasaNormal(techo t, piso p){
        pisoPrincipal = &p;
        techoCasa = &t;
    }
};

class CasaDosPisos{
    public:
        piso* piso1;
        piso* piso2;
        techo* techoCasa;

    CasaDosPisos(techo t, piso p1, piso p2){
        techoCasa = &t;
        piso1 = &p1;
        piso2 = &p2;
    }
};

class Edificio{
    public:
        vector<piso> pisos;
        techo* techoEdificio;

    Edificio(techo t){
        techoEdificio = &t;
    }

    void agregarPiso(double w, double h){
        pisos.push_back(piso(w, h));
    }
};

class Factory{
    public:
        double defWidth, defHeight;

        Factory(double w, double h) {
            defWidth = w;
            defHeight = h;
        }

        CasaNormal& createCasaNormal(){
            static CasaNormal instance(techo(2.5, "normal"), piso(defWidth, defHeight));
            return instance;
        }

        CasaDosPisos& createCasaDosPisos(){
            static CasaDosPisos instance(techo(2.5, "normal"), piso(defWidth, defHeight), piso(defWidth, defHeight));
            return instance;
        }

        Edificio& createEdifio(int cantidadPisos){
            static Edificio instance(techo(1, "edificio"));
            for (int i = 0; i < cantidadPisos; i++) {
                instance.agregarPiso(defWidth, defHeight);
            }
            return instance;
        }

        ~Factory() {}
};

int main(){
    Factory f(7, 3.5);

    CasaNormal test = f.createCasaNormal();

    cout << test.pisoPrincipal->width << endl;

    return 0;
}
