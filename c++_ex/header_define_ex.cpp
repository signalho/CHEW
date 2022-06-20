/*
// 열거형의 도입 변수지정으로 인한 메모리 낭비 삭제
#include <stdio.h>
enum { RED, BLUE, WHITE, BLACK };  // red = 0, blue = 1, .... 이런식으로 진행
int main() {
    int palette = RED;
    switch (palette) {
    case RED:
        printf("palette : RED \n");
        break;
    case BLUE:
        printf("palette : BLUE \n");
        break;

    case WHITE:
        printf("palette : WHITE \n");
        break;
    case BLACK:
        printf("palette : BLACK \n");
        break;
    }
}
*/

/*
// ifdef 
//언제나 ifdef 는 endif 와 짝을 지어서 사용하는데, 
//ifdef 에서 지정한 매크로가 정의되어 있다면 
//ifdef 와 endif 속에 있는 코드가 포함되고 
//그렇지 않다면 코드에 포함되지 않는 것으로 간주 됩니다.

#include <stdio.h>
#define A
int main() {
#ifdef A
    printf("AAAA \n");
#endif
#ifdef B
    printf("BBBB \n");
#endif
    return 0;
}
*/

/*
//사용하는 변수 용도별로 나눌수 잇음
#define CACULATOR_MODEL_1

#ifdef CALCULATOR_MODEL_1
float var1, var2;
#endif
#ifdef CALCULATOR_MODEL_2
double var1, var2;
#endif;// do something
// do something

*/

//리턴값이 필요 없는 곳에서는 void
//리턴값 주는 곳에서는 int, float 등등
