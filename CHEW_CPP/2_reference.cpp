#include <iostream>
using namespace std;

// if Function returns references such as FuncOne and FuncTwo,
// it could be stored to references and variables
int &RefRetFuncOne(int &ref1){
    ref1++;
    return ref1;
}
int &RefRetFuncTwo(int &ref2){
    ref2++;
    return ref2;
}
// FuncThree could only be stored to variables ex) int
int RefRetFuncThree(int &ref3){
    ref3++;
    return ref3;
}

int main(void){
    int num1 = 1;
    int &num2 = RefRetFuncOne(num1);  // int &ref1=num1, int &num2=ref1 -> num1=ref1=num2
    int num3 = RefRetFuncTwo(num1);   // int &ref2=num1, int num3=ref2  -> num1=ref2 != num3
    int num4 = RefRetFuncThree(num1); // int &ref3=num1, int num4=ref3  -> num1=ref3 != num4

    num1++; 
    num2++; 
    num3 += 100; 
    num4 += 200;
    cout<<num1<<endl;
    cout<<num2<<endl;
    cout<<num3<<endl;
    cout<<num4<<endl;
    return 0;
}