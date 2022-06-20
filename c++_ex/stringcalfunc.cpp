/*문자열을 자유롭게 다루기 위한 함수 모음*/
// 문자열 내의 총 문자의 수를 세는 함수
// 문자열을 복사하는 함수
// 문자열을 합치는 함수
// 문자열을 비교하는 함수

#include <stdio.h>


// 문자열 내의 총 문자의 수를 세는 함수
int str_length(char* str) {
    int i = 0;
    while (str[i]) {
        i++;
    }
    return i;
}

int length_cal() {
    char str[] = { "What is your name?" };
    printf("이 문자열의 길이 : %d \n", str_length(str));
    return 0;
}


// 문자열을 복사하는 함수
int copy_str(char* dest, char* src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0'; //마지막에 NULL 문자 삽입
    return 1;
}

int copy_string() {
    char str1[] = "hello";
    char str2[] = "hi";

    printf("복사 이전 : %s \n", str1);
    copy_str(str1, str2);
    printf("복사 이후 : %s \n ", str1);
    return 0;
}


// 문자열을 합치는 함수
int stradd(char* dest, char* src) {
    /* dest 의 끝 부분을 찾는다.*/
    while (*dest) {
        dest++;
    }
    /*
    while 문을 지나고 나면 dest 는 dest 문자열의 NULL 문자를 가리키고 있게 된다.
    이제 src 의 문자열들을 dest 의 NULL 문자 있는 곳 부터 복사해넣는다.
    */
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    /* 마지막으로 dest 에 NULL 추가 (왜냐하면 src 에서 NULL 이 추가 되지
     * 않았으므로) */
    *dest = '\0';
    return 1;
}

int add_string() {
    char str1[100] = "hello my name is ";
    char str2[] = "Psi";

    printf("합치기 이전 : %s \n", str1);
    stradd(str1, str2);
    printf("합친 이후 : %s \n", str1);
    return 0;
}


// 문자열을 비교하는 함수
int compare(char* str1, char* str2) {
    while (*str1) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    if (*str2 == '\0') return 1;
    return 0;
}

int compare_string() {
    char str[20] = "hello every1";
    char str2[20] = "hello everyone";
    char str3[20] = "hello every1 hi";
    char str4[20] = "hello every1";

    if (compare(str, str2)) {
        printf("%s 와 %s 는 같다 \n", str, str2);
    }
    else {
        printf("%s 와 %s 는 다르다 \n", str, str2);
    }

    if (compare(str, str3)) {
        printf("%s 와 %s 는 같다 \n", str, str3);
    }
    else {
        printf("%s 와 %s 는 다르다 \n", str, str3);
    }

    if (compare(str, str4)) {
        printf("%s 와 %s 는 같다 \n", str, str4);
    }
    else {
        printf("%s 와 %s 는 다르다 \n", str, str4);
    }
    
    return 0;
}

/*********************************************************************/
/*********************************************************************/
/*********************************************************************/
/*
int main() {
    length_cal();
    copy_string();
    add_string();
    compare_string();

    return 0;
}
*/