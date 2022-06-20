/*
// memcpy 함수 

#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "I love Chewing C hahaha";
    char str2[50];
    char str3[50];

    memcpy(str2, str, strlen(str) + 1); //끝에 1 더해주는건 NULL까지 같이 가져오려고
    memcpy(str3, "hello", 6);

    printf("%s \n", str);
    printf("%s \n", str2);
    printf("%s \n", str3);

    return 0;
}
*/

/*
I love Chewing C hahaha
I love Chewing C hahaha
hello
*/

/*
// memmove 함수 

#include <stdio.h>
#include <string.h>

int main() {
    char str[50] = "I love Chewing C hahaha";

    printf("%s \n", str);
    printf("memmove 이후 \n");
    memmove(str + 23, str + 17, 6);
    printf("%s", str);

    return 0;
}
*/

/*
I love Chewing C hahaha
memmove 이후
I love Chewing C hahahahahaha
*/

/*
// memcmp 함수 

#include <stdio.h>
#include <string.h>

int main() {
    int arr[10] = { 1, 2, 3, 4, 5 };
    int arr2[10] = { 1, 2, 3, 4, 5 };

    if (memcmp(arr, arr2, 5) == 0) //5는 5byte
        printf("arr 과 arr2 는 일치! \n");
    else
        printf("arr 과 arr2 는 일치 안함 \n");

    return 0;
}
*/

/*
arr 과 arr2 는 일치!
*/
