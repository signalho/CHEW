#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// memory for 'something' should be accessible and rewritten 
// whenever the function is going on or over
// Using <stdlib.h>
// void *malloc(size_t size); -> int *ptr = (int *)malloc(sizeof(int)*size_variable);
// void *malloc(size_t size); -> int *ptr = (int *)malloc(sizeof(int)*7);
// void free(void *ptr);

// There is other alternative
// void *calloc(size_t elt_count, size_t elt_size);

// You can also change malloc's memory size
// void *realloc(void *ptr, size_t size);
// ex) ptr = (int *)realloc(ptr, sizeof(int)*5);

int dynamicallocation(void){
    int *ptr1 = (int *)malloc(sizeof(int));
    int *ptr2 = (int *)malloc(sizeof(int)*7);
    int i;

    *ptr1 = 20;
    for(i=0; i<7; i++)
        ptr2[i]=i+1;
    printf("%d \n", *ptr1);

    for(i=0; i<7; i++)
        printf("%d ", ptr2[i]);
    
    free(ptr1);
    free(ptr2);
    return 0;
}
//////////////////////////////////////////////////////////////////////
char * ReadUserName(int i){
    char *name = (char *)malloc(sizeof(char)*30);
    // printf("What's your name? ");
    // gets(name);
    name = "K E E";
    if (i == 2){
        name = "K E E E";
    }
    return name;
}
int ReadUserNamemain(void){
    char *name1;
    char *name2;
    int i = 1;
    name1 = ReadUserName(i);
    printf("name1: %s \n", name1);
    i++;
    name2 = ReadUserName(i);
    printf("name2: %s \n", name2);
    
    printf("again name1: %s \n", name1);
    free(name1);
    printf("again name2: %s \n", name2);
    free(name2);
    return 0;
}
//////////////////////////////////////////////////////////////////////
int prob(void){
    int maxlen, len, i;
    char * str;
    printf("max length?");
    scanf("%d", &maxlen);
    getchar(); // delete \n
    str = (char *)malloc(sizeof(char)*(maxlen+1));

    printf("string");
    fgets(str, maxlen+1, stdin);
    str[strlen(str)-1]=0;
    len=strlen(str);

    for (i=len; i>0; i--){
        if(str[i]==' '){
            printf("%s ", &str[i+1]);
            str[i]=0;
        }
    }
    printf("%s", &str[0]);
    free(str);
    return 0;
}
//////////////////////////////////////////////////////////////////////
/* 2 차원배열동적할당의활용*/
void get_average(int **arr, int numStudent, int numSubject) { 
    int i, j, sum;
    for (i = 0; i < numSubject; i++) { 
        sum = 0;
        for (j = 0; j < numStudent; j++) {
            sum += arr[i][j];
        }
        printf("과목 %d 평균 점수 : %d \n", i, sum / numStudent); 
    }
}
int twodimdynall(int argc, char **argv) { 
    int i, j, input, sum = 0;
    int subject, students;
    int **arr;
    // 우리는 arr[subject][students] 배열을 만들 것이다. 
    printf("과목 수 : ");
    scanf("%d", &subject); 
    printf("학생의 수 : ");
    scanf("%d", &students);
    
    arr = (int **)malloc(sizeof(int *) * subject);
    for (i = 0; i < subject; i++) {
        arr[i] = (int *)malloc(sizeof(int) * students);
    }
    for (i = 0; i < subject; i++) {
        printf("과목 %d 점수 --------- \n", i);
        for (j = 0; j < students; j++) { 
            printf("학생 %d 점수 입력 : ", j); 
            scanf("%d", &input);
            arr[i][j] = input;
        }
    }
    get_average(arr, students, subject);
    for (i = 0; i < subject; i++) { 
        free(arr[i]);
    } 
    free(arr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
/*STRUCT DYNALLOCATION*/
struct Something {
    int a, b; 
};
int structdynall() {
    struct Something *arr; 
    int size, i;
    printf("원하시는 구조체 배열의 크기 : "); 
    scanf("%d", &size);
    
    arr = (struct Something *)malloc(sizeof(struct Something) * size);
    for (i = 0; i < size; i++) { 
        printf("arr[%d].a : ", i); 
        scanf("%d", &arr[i].a); 
        printf("arr[%d].b : ", i); 
        scanf("%d", &arr[i].b);
    }
    for (i = 0; i < size; i++) {
        printf("arr[%d].a : %d , arr[%d].b : %d \n", i, arr[i].a, i, arr[i].b);
    }
    free(arr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
int main(void){
    dynamicallocation();
    ReadUserNamemain();
    // prob();
    // twodimdynall();
    // structdynall();
    return 0;
}