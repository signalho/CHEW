/* 널 뽀개기 */
#include <stdio.h>

int ex1() {
    char null_1 = '\0';  // 이 3 개는 모두 동일하다
    char null_2 = 0;
    char null_3 = (char)NULL;  // 모두 대문자로 써야 한다

    char not_null = '0';

    printf("NULL 의 정수(아스키)값 : %d, %d, %d \n", null_1, null_2, null_3);
    printf("'0' 의 정수(아스키)값 : %d \n", not_null);

    return 0;
}

int ex2() {
    char sentence_1[4] = { 'P', 's', 'i', '\0' };
    char sentence_2[4] = { 'P', 's', 'i', 0 };
    char sentence_3[4] = { 'P', 's', 'i', (char)NULL };
    char sentence_4[4] = { "Psi" };

    printf("sentence_1 : %s \n", sentence_1);  // %s 를 통해서 문자열을 출력한다.
    printf("sentence_2 : %s \n", sentence_2);
    printf("sentence_3 : %s \n", sentence_3);
    printf("sentence_4 : %s \n", sentence_4);

    return 0;
}

int length_cal_mine() {
    char strin[] = { "hello my bro" };
    int count = 0;
    while (strin[count]) {
        count++;
    }
    printf("string count : %d \n", count);
    return 0;
}

int buffer_1() {
    int num;
    char c;

    printf("숫자를 입력하세요 : ");
    scanf_s("%d", &num, 20);

    getchar();

    printf("문자를 입력하세요 : ");
    scanf_s("%s", &c, 20);
    return 0;
}

int main() {
    //ex1();
    //ex2();
    length_cal_mine();
    //buffer_1();

    return 0;
}
