#include <iostream>
using namespace std;

// 'this' pointer
// points out object itself
class TwoNumber{
    private:
        int num1;
        int num2;
    public:
        TwoNumber(int num1, int num2){
            this->num1 = num1;
            this->num2 = num2;
        }
        // Avoid ambiguous function
        // TwoNumber(int num1, int num2) : num1(num1), num2(num2) {}
        void ShowTwoNumber(){
            cout<<this->num1<<endl;
            cout<<this->num2<<endl;
        }
};
void TwoNumbermain(void){
    TwoNumber two(2,4);
    two.ShowTwoNumber();
}
////////////////////////////////////////////////////////////
// Self Reference
// reference that references object itself
class SelfRef{
    private:
        int num;
    public:
        SelfRef(int n) : num(n){
            cout<<"object created"<<endl;
        }
        SelfRef& Adder(int n){
            num += n;
            return *this;
        }
        SelfRef& ShowTwoNumber(){
            cout<<num<<endl;
            return *this;
        }
};
void SelfRefmain(void){
    SelfRef obj(3);
    SelfRef &ptr = obj.Adder(2);
    obj.ShowTwoNumber();
    ptr.ShowTwoNumber();
    ptr.Adder(1).ShowTwoNumber().Adder(2).ShowTwoNumber();
}
////////////////////////////////////////////////////////////
int main(void){
    TwoNumbermain();
    SelfRefmain();
    return 0;
}