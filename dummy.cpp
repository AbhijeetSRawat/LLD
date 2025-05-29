#include<iostream>
using namespace std;

class animal{
    public:
    virtual void voice(){
        cout<<"animal is speaking";
    }
};

class dog : public animal{

    public:
    void voice(){
        cout<<"dog is barking";
    }

};

int main(){

    animal* a = new animal();

    a->voice();

    return 0;
}