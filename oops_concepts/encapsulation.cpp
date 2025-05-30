#include <iostream>
using namespace std;

class Car
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;
    string TyreCompany = "MRF";

public:
    Car(string brand, string model)
    {
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
    }

    string getTyreCompany()
    {
        cout << "The tyre company is - " << TyreCompany << endl;
    }

    void setTyreCompany(string Tyre)
    {
        this->TyreCompany = Tyre;
        cout << "Your car's tyre has been set to " << TyreCompany << endl;
    }

    void startEngine()
    {
        this->isEngineOn = true;
        cout << "The engine has been started vroom !!! \n";
    }

    void shiftGear(int gear)
    {
        this->currentGear = gear;
        cout << "The gear has been changed to : " << currentGear << endl;
    }

    void accelerate()
    {
        this->currentSpeed = currentSpeed + 20;
        cout << "Your speed is now : " << currentSpeed << endl;
    }

    void brake()
    {
        this->currentSpeed = currentSpeed - 20;
        cout << "Your speed is now : " << currentSpeed << endl;
    }

    void engineOff()
    {
        this->isEngineOn = false;
        currentGear = 0;
        currentSpeed = 0;
        cout << "The engine is off now !!!" << endl;
    }

    ~Car()
    {
        cout << "The car is getting destroyed ... BOOM !!!";
    }
};

int main()
{

    Car *BMW = new Car("BMW", "C327N");

    BMW->getTyreCompany();

    BMW->startEngine();
    BMW->accelerate();
    BMW->shiftGear(3);
    BMW->accelerate();
    BMW->brake();
    BMW->engineOff();

    BMW->setTyreCompany("CEAT");
    BMW->getTyreCompany();

    delete BMW;

    return 0;
}