#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Mago{
    public:
        int fuego = 15, hielo = 20, trueno = 10;

        Mago(){}

        virtual int lanzarMagia() = 0;
};

class MagoFuego : public Mago{
    public:
        MagoFuego(){

        }

        int lanzarMagia() {
            return fuego;
        }
};

class MagoHielo : public Mago{
    public:
        MagoHielo(){

        }

        int lanzarMagia() {
            return hielo;
        };
};

class MagoTrueno : public Mago{
    public:
        MagoTrueno(){

        }

        int lanzarMagia() {
            return trueno;
        };
};

class Guerrero{
    public:
        int fuerza = 10;

        Guerrero(){}

        string atacar(){
            return "ataca con su arma causando: " + to_string(fuerza) + " puntos de daño.";
        }
};

class Adapter : public Guerrero{
    public:
        Mago* mago;

        Adapter(Mago& m){
            mago = &m;
        }

        string atacar(){
            string ataque = "ataca lanzando magia de ";
            if (MagoFuego* mf =  dynamic_cast<MagoFuego*>(mago)){
                ataque += "fuego causando: " + to_string(mf->lanzarMagia()) + " puntos de daño.";
            }else if (MagoHielo* mh =  dynamic_cast<MagoHielo*>(mago)){
                ataque += "hielo causando: " + to_string(mh->lanzarMagia()) + " puntos de daño.";
            }else if (MagoTrueno* mt =  dynamic_cast<MagoTrueno*>(mago)){
                ataque += "trueno causando: " + to_string(mt->lanzarMagia()) + " puntos de daño.";
            }
            return ataque;
        }
};


int main(){
    Guerrero g;
    MagoFuego mf;
    MagoHielo mh;
    MagoTrueno mt;
    Adapter adapMagoF(mf);
    Adapter adapMagoH(mh);
    Adapter adapMagoT(mt);

    cout << g.atacar() << endl;
    cout << adapMagoF.atacar() << endl;
    cout << adapMagoH.atacar() << endl;
    cout << adapMagoT.atacar() << endl;

    return 0;
}
