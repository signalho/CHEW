#include <iostream>
#include <cstring>
using namespace std;

// Characteristics of Pointer function
class First {
    public:
        void FirstFunc() { cout<<"FirstFunc"<<endl; }
};
class Second : public First {
    public:
        void SecondFunc() { cout<<"SecondFunc"<<endl; }
};
class Third : public Second {
    public:
        void ThirdFunc() { cout<<"ThirdFunc"<<endl; }
};
void pntrch(void){
    Third * tptr = new Third();
    Second * sptr = tptr;
    First * fptr = sptr;

    // Can access to the members defined in the class
    // by the type of the pointer
    // ex) fptr is the pointer of class 'First' -> X access to Second or Third!
    tptr->FirstFunc();
    tptr->SecondFunc();
    tptr->ThirdFunc();

    sptr->FirstFunc();
    sptr->SecondFunc();
    // sptr->ThirdFunc();

    fptr->FirstFunc();
    // fptr->SecondFunc();
    // fptr->ThirdFunc();
    cout<<endl<<endl;
    delete tptr;
}
////////////////////////////////////////////////////////////
// Function Override
class Firstt {
    public:
        void MyFunc() { cout<<"FirstFunc"<<endl; }
};
class Secondd : public Firstt {
    public:
        void MyFunc() { cout<<"SecondFunc"<<endl; }
};
class Thirdd : public Secondd {
    public:
        void MyFunc() { cout<<"ThirdFunc"<<endl; }
};
void FncOvr(void){
    Thirdd * tptr = new Thirdd();
    Secondd * sptr = tptr;
    Firstt * fptr = sptr;

    // Since 'tptr' is 'Third' pointer,
    // the lastly overrided 'Third' class's MyFunc is shown
    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    cout<<endl<<endl;
    delete tptr;
}
////////////////////////////////////////////////////////////
// Function 'Virtual' Override
class Firsttt {
    public:
        virtual void MyFunc() { cout<<"FirstFunc"<<endl; }
};
class Seconddd : public Firsttt {
    public:
        virtual void MyFunc() { cout<<"SecondFunc"<<endl; }
};
class Thirddd : public Seconddd {
    public:
        virtual void MyFunc() { cout<<"ThirdFunc"<<endl; }
};
void FncVirOvr(void){
    Thirddd * tptr = new Thirddd();
    Seconddd * sptr = tptr;
    Firsttt * fptr = sptr;

    // if the function is declared as a 'Virtual' function,
    // function is called by the object the pointer really points out
    // ex) fptr's MyFunc points out Third's MyFunc!
    fptr->MyFunc();
    sptr->MyFunc();
    tptr->MyFunc();
    cout<<endl<<endl;
    delete tptr;
}
////////////////////////////////////////////////////////////
int main(void){
    pntrch();
    FncOvr();
    FncVirOvr();
    return 0;
}