#include <stdio.h>
 
///////삼 항 연산자///Three Operand//////////////////////
int ThreeOp(void){
    int num=-10, abs;
    abs = num>0? num : num*(-1); // True : False
    printf("%d",abs);
    return 0;
}
//////////////////////////////////////////////////////

///////Static Local Variable//////////////////////////
///////선언된 함수 내에서 계속 존재//////////////////////////
void func(void){
    static int n1=0; // Lasts in func
    int n2=0;
    n1++, n2++;
    printf("%d %d \n",n1,n2);
}
int StaticVariable(void){
    int i;
    for(i=0;i<3;i++){
        func();
    }
    // ThreeOp();
    return 0;
}
//////////////////////////////////////////////////////
int main(void){
    ThreeOp();
    StaticVariable();
    return 0;
}
