#include <iostream>
#include <vector>
#include <math.h>

#define pow2(X) X*X

using namespace std;

class point{
    public: 
        int x, y;
    
    point(){}

    point(int nx, int ny){
        x = nx;
        y = ny;
    }


};

class PlanoCartesiano {
    public: 
        vector<point> pointList;

    PlanoCartesiano(){}

    static PlanoCartesiano& getInstance(){
        static PlanoCartesiano instance;
        return instance;
    }

    void addPoint(double x, double y){
        pointList.push_back(point(x, y));
    }

    double calcularDistancia(int i1, int i2){
        double distanciaX, distanciaY;
        distanciaX = abs(pow2(pointList[i1].x - pointList[i2].x));
        distanciaY = abs(pow2(pointList[i1].y - pointList[i2].y)); 
        return sqrt(distanciaX + distanciaY);
    }

    ~PlanoCartesiano(){
    }
};

int main(){
    PlanoCartesiano& pc = PlanoCartesiano::getInstance();
    
    pc.addPoint(1,1);
    pc.addPoint(2,2);
    pc.addPoint(5,5);
    pc.addPoint(10,0);
    pc.addPoint(100,90);
    
    cout << "distancia: " << pc.calcularDistancia(0,2) << endl;

    return 0;
}