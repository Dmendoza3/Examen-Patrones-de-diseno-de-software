#include <iostream>
#include <string>

using namespace std;

class classExtranjera{
    public:
        double x;

        classExtranjera(){}

        string metodoExtranjero(){
            return "EX";
        }
};

class classNormal{
    public:
        classNormal(){}

        string metodoNormal(){
            return "N";
        }
};

class Adapter : public classNormal{
    public:
        classExtranjera* classEx;

        Adapter(classExtranjera ex){
            classEx = &ex;
        }

        string metodoNormal(){
            return classEx->metodoExtranjero();
        }
};


int main(){
    classNormal n;
    classExtranjera e;
    Adapter a(e);

    cout << a.metodoNormal();

    return 0;
}
