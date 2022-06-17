#include <iostream>
#include <cstring>
using namespace std;

// Inheritence [@@ is a ##]
// ex) laptop is a computer -> class laptop : public computer
class Computer {
    private:
        char owner[50];
    public:
        Computer(char * name) {
            strcpy(owner,name);
        }
        void Calculate(){
            cout<<"calculating"<<endl;
        }
};
class NotebookComp : public Computer {
    private:
        int Battery;
    public:
        NotebookComp(char * name, int initChag)
            : Computer(name), Battery(initChag) {}
        void Charging() { Battery += 5; }
        void UseBattery() { Battery -= 1; }
        void MovingCal() {
            if (GetBatteryInfo()<1) {
                cout<<"need charge"<<endl;
                return;
            }
            cout<<"moving ";
            Calculate();
            UseBattery();
        }
        int GetBatteryInfo() { return Battery; }
};
class TabletNotebook : public NotebookComp {
    private:
        char regstPenModel[50];
    public:
        TabletNotebook(char * name, int initChag, char * pen)
            : NotebookComp(name, initChag)
        {
            strcpy(regstPenModel, pen);
        }
        void Write(char * penInfo){
            if(GetBatteryInfo()<1){
                cout<<"need charge"<<endl;
                return;
            }
            if(strcmp(regstPenModel, penInfo)!=0){
                cout<<"not our pen";
                return;
            }
            cout<<"processing"<<endl;
            UseBattery();
        }
};
////////////////////////////////////////////////////////////
int main(void){
    NotebookComp nc("hey", 5);
    TabletNotebook tn("heey", 5, "wrting");
    nc.MovingCal();
    tn.Write("wrting");
    return 0;
}