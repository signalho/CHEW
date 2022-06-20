/*
// 매크로 함수
#include <stdio.h>
#define square(x) (x) * (x)

int main(int argc, char** argv) {
    printf("square(3) : %d \n", square(3 + 1));

    return 0;
}

//이런식으로
#define RADTODEG(x) (x) * 57.295
#define PrintVariableName(var) printf(#var "\n");
#define AddName(x, y) x##y   //x,y 인자를 xy라는 인자로 합쳐줌


//또는 inline 형식으로  이러면 귀찮게 괄호 안쳐줘도 상관 없이 다 해줌
__inline int square(int a) { return a * a; }

*/

