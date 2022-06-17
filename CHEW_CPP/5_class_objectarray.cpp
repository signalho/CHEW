#include <iostream>
#include <cstring>
using namespace std;

class Person{
    private:
        char *name;
        int age;
    public:
        Person(char *myname, int myage){
            int len = strlen(myname) + 1;
            name = new char[len];
            strcpy(name, myname);
            age = myage;
        }
        Person(){
            name = NULL;
            age = 0;
            cout<<"called Person()"<<endl;
        }
        void SetPersonInfo(char *myname, int myage){
            name = myname;
            age = myage;
        }
        void ShowInfo() const{
            cout<<"name : "<<name<<endl;
            cout<<"age : "<<age<<endl;
        }
        ~Person() {
            delete []name;
            cout<<"Destructor"<<endl;
        }
};

int main(void){
    Person parr[3];
    char namestr[100];
    char *strptr;
    int age;
    int len;

    for(int i=0; i<3; i++){
        cout<<"name: ";
        cin>>namestr;
        cout<<"age: ";
        cin>>age;
        len = strlen(namestr) + 1;
        strptr = new char[len];
        strcpy(strptr, namestr);
        parr[i].SetPersonInfo(strptr, age);
        parr[i].ShowInfo();
    }
    return 0;
}
