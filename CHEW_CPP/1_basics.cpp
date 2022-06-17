#include <iostream>
// namespace makes code concise
// ex) std::cout~ to cout~
using namespace std;

inline int SQUARE(int x){
    return x*x;
}
namespace Hybrid{
    void Hybfunc(void){
        cout<<"func"<<endl;
    }
    namespace Hybvariable{
        int a, b;
    }
}
int main(void){
    int num=20;
    cout<<"Hi"<<endl;
    cout<<num<<' '<<endl;

    // // user input, no need to indicate data type for cout
    // char name[30];
    // cin>>name;
    // cout<<name<<endl;

    // inline func, similar with macro but easier
    cout<<SQUARE(5)<<endl;

    // namespace func
    Hybrid::Hybfunc();
    using Hybrid::Hybfunc; // make it easier
    Hybfunc();
    
    namespace Hyb = Hybrid::Hybvariable; //make shortcut
    Hyb::a=1;
    cout<<Hyb::a<<endl;

    return 0;
}
