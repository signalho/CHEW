#include <iostream>
using namespace std;

// Constructor class example
// ++ Member Initializer, 'this' pointer
class Constructclass{
    private:
        int num1;
        int num2;
    public:
        Constructclass(){
            num1 = 0;
            num2 = 0;
        }
        Constructclass(int n){
            num1 = n;
            num2 = 0;
        }
        Constructclass(int n1, int n2){
            num1 = n1;
            num2 = n2;
        }
        /* Don't make constructor ambiguous
        Constructclass(int n1=0, int n2=0){
            num1 = n1;
            num2 = n2;
        }*/
        void Showdata() const{
            cout<<num1<<", "<<num2<<endl;
        }
};
void const_ex(void){
    Constructclass sc1;
    sc1.Showdata();
    Constructclass sc2(100);
    sc2.Showdata();
    Constructclass sc3(100,200);
    sc3.Showdata();
}
////////////////////////////////////////////////////////////
// Member Initializer
class MI{
    private:
        int num1;
        int num2;
    public:
        // MEMBER INITIALIZER
        MI(int n1, int n2) : num1(n1), num2(n2){}
        void Showdata() const{
            cout<<num1<<", "<<num2<<endl;
        }
};
class AAA{
    public:
        AAA(){
            cout<<"empty object"<<endl;
        }
        void ShowName(){
            cout<<"I'm class AAA"<<endl;
        }
};
class BBB{
    private:
        AAA &ref;
        const int &num;
    public:
        // Reference Member
        BBB(AAA &r, const int &n) : ref(r), num(n) {}
        void ShowName(){
            ref.ShowName();
            cout<<"I'm class BBB, "<<num<<endl<<endl;
        }
};
void mem_ex(void){
    MI mi1(1,2);
    mi1.Showdata();

    AAA obj1;
    BBB obj2(obj1, 10);
    obj2.ShowName();
}
////////////////////////////////////////////////////////////
// Private constructor & Destructor
class PrivConstruc{
    private:
        int num;
    public:
        // initial constructor
        PrivConstruc() : num(3) {}
        // reference member constructor
        PrivConstruc& CreateInitObj(int n) const{
            PrivConstruc *ptr = new PrivConstruc(n);
            return *ptr;
        }
        void Shownum() const {
            cout<<"num : "<<num<<endl;
        }
        // Destructor
        ~ PrivConstruc(){
            // delete dynamic memory
            // delete num;
            cout<<"Destructor"<<endl;
        }
    // private constructor
    private:
        PrivConstruc(int n) : num(n) {
            cout<<"called private constructor"<<endl;
        }
};
void Priv_ex(void){
    PrivConstruc PC;
    PC.Shownum();
    PrivConstruc &obj1 = PC.CreateInitObj(13);
    obj1.Shownum();
    delete &obj1;
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
int main(void){
    const_ex();
    mem_ex();
    Priv_ex();
    return 0;
}

