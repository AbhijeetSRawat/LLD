#include <iostream>
using namespace std;

class Car
{
public:
    virtual void startEngine() = 0;
    virtual void shiftGear(int gear) = 0;
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void engineOff() = 0;
    virtual ~Car() {};
};

class sportsCar : public Car
{
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    sportsCar(string brand, string model)
    {
        this->brand = brand;
        this->model = model;
        isEngineOn = false;
        currentSpeed = 0;
        currentGear = 0;
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
};

int main()
{

    Car *BMW = new sportsCar("BMW", "C327N");

    BMW->startEngine();
    BMW->accelerate();
    BMW->shiftGear(3);
    BMW->accelerate();
    BMW->brake();
    BMW->engineOff();

    return 0;
}