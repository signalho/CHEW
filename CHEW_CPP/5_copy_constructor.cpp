#include <iostream>
using namespace std;

// copy constructor
class Sosimple{
    private:
        int num1;
        int num2;
    public:
        Sosimple(int num1, int num2) : num1(num1), num2(num2) {}
        Sosimple(Sosimple &copy) : num1(copy.num1), num2(copy.num2) {
            cout<<"Called Sosimple(Sosimple &copy)"<<endl;
        }
        // Default copy constructor
        // Sosimple(const Sosimple &copy) : num1(copy.num1), num2(copy.num2) {}
        void Showdata(void){
            cout<<num1<<", "<<num2<<endl;
        }
};
void CPY(void){
    Sosimple sim1(10,20);
    Sosimple sim2 = sim1;    // same as Sosimple sim2(sim1);
    
    sim2.Showdata();
}
////////////////////////////////////////////////////////////
// Shallow & Deep copy
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
        // Deep copy
        // copies reference of the string
        Person(Person &copy) : age(copy.age){
            name = new char[strlen(copy.name)+1];
            strcpy(name, copy.name);
        }
        void ShowInfo() const{
            cout<<name<<", "<<age<<endl;
        }
        ~Person(){
            delete []name;
            cout<<"Called Destructor"<<endl;
        }
};
void SDCPY(void){
    Person p1("inho kee",27);

    // <Shallow copy>
    // Problem comes out when destructor(dynamic allocation) involves!
    // member - member simple copy makes both objects reference the same literal
    Person p2 = p1;

    p1.ShowInfo();
    p2.ShowInfo();
}
////////////////////////////////////////////////////////////
int main(void){
    CPY();
    SDCPY();
    return 0;
}