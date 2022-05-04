#include <iostream>
#include <vector>
using namespace std;

class Gadget{
    protected:
        bool activated;
        string name;
    public:
        Gadget(){
            activated = false;
        }
        virtual void accion() = 0;
        string getName(){
            return name;
        }
};

class YellowLed:public Gadget{
public:
    YellowLed():Gadget(){
        name = "Yellow_Led";
    }
    void accion() override{
        if(!activated)
            cout<<"Yellow on"<<endl;
        else
            cout<<"Yellow off"<<endl;
    }
};

class RedLed:public Gadget{
public:
    RedLed():Gadget(){
        name = "Red_Led";
    }
    void accion() override{
        if(!activated)
            cout<<"Red on"<<endl;
        else
            cout<<"Red off"<<endl;
    }
};

class WhiteLed:public Gadget{
public:
    WhiteLed(): Gadget(){
        name = "White_Led";
    }
    void accion() override{
        if(!activated)
            cout<<"White on"<<endl;
        else
            cout<<"White off"<<endl;
    }
};

class Fan:public Gadget{
    public:
        Fan():Gadget(){
            name = "Fan";
        }
        void accion() override{
            if(!activated)
                cout<<"Fan on"<<endl;
            else
                cout<<"Fan off"<<endl;
        }
};

class MainControl{
private:
    vector<Gadget*> gadget;
public:
    MainControl(){};
    MainControl(vector<Gadget*> _gadget){
        gadget = _gadget;
    }
    void setLEDs(vector<Gadget*> _gadget){
        gadget = _gadget;
    }
    void setGadgets(vector<Gadget*> _gadget){
        gadget = _gadget;
    }
    void activateGadgets(string _gadget){
        for(int i=0; i<gadget.size(); i++)
            if(gadget[i]->getName() == _gadget){
                cout<<gadget[i]->getName()<<endl;
                gadget[i]->accion();
            }
    }
};

int main() {
    MainControl *control = new MainControl();
    vector<Gadget*> gadgets;
    auto *n = new YellowLed();
    auto *n1 = new RedLed();
    auto *n2 = new WhiteLed();
    auto *fan = new Fan();
    gadgets.push_back(n);
    gadgets.push_back(n1);
    gadgets.push_back(n2);
    gadgets.push_back(fan);
    control->setGadgets(gadgets);
    control->activateGadgets("Yellow_Led");
}
