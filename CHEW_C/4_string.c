#include <stdio.h>
/*
To handle string freely in C lang you need 4 func
• 문자열 내의 총 문자의 수를 세는 함수 
• 문자열을 복사하는 함수
• 문자열을 합치는 함수 (즉 더하는)
• 문자열을 비교하는 함수 
*/ 

int str_length(char *str) { 
    int i = 0;
    while (str[i]) {
        i++; 
    }
    return i; 
}

int copy_str(char *dest, char *src) { 
    while (*src) {
        *dest = *src;
        src++; // 그 다음 문자를 가리킨다. 
        dest++;
    }
    *dest = '\0';
    return 1;
}

int stradd(char *dest, char *src) {
    /* dest 의 끝 부분을 찾는다.*/ 
    while (*dest) { 
        dest++;
    }
    /* while 문을 지나고 나면 dest 는 dest 문자열의 NULL 문자를 가리키고 있게 된다. 
    이제 src 의 문자열들을 dest 의 NULL 문자 있는 곳 부터 복사해넣는다. */
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }
    /* 마지막으로 dest 에 NULL 추가 
    (왜냐하면 src 에서 NULL 이 추가 되지 * 않았으므로) */
    *dest = '\0'; 
    return 1;
}

int compare(char *str1, char *str2) { 
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
