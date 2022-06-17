#include <stdio.h>
#include <string.h>
 
///////삼 항 연산자///Three Operand//////////////////////
int ThreeOp(void){
    int num=-10, abs;
    abs = num>0? num : num*(-1); // True : False
    printf("%d",abs);
    return 0;
}
///////////////////////////////////////////////////////

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
/*memcpy func*/
int memcpyfunc() {
    char str[50] = "I love Chewing C hahaha"; 
    char str2[50];
    char str3[50];
    memcpy(str2, str, strlen(str) + 1);
    memcpy(str3, "hello", 6);
    printf("%s \n", str); printf("%s \n", str2); printf("%s \n", str3);
    return 0;
}
/*memmove func*/
int memmovefunc() {
    char str[50] = "I love Chewing C hahaha";
    printf("%s \n", str); 
    printf("memmove 이후 \n"); 
    memmove(str + 23, str + 17, 6); 
    printf("%s", str);
    return 0; 
}
/*memcmp func*/
int memcmpfunc() {
    int arr[10] = {1, 2, 3, 4, 5}; 
    int arr2[10] = {1, 2, 3, 4, 5};
    if (memcmp(arr, arr2, 5) == 0) 
        printf("arr 과 arr2 는 일치! \n");
    else
        printf("arr 과 arr2 는 일치 안함 \n"); 
    return 0;
}
//////////////////////////////////////////////////////
int main(void){
    ThreeOp();
    StaticVariable();
    return 0;
}