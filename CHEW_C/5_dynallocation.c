#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// memory for 'something' should be accessible and rewritten 
// whenever the function is going on or over
// Using <stdlib.h>
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
int main(void){
    dynamicallocation();
    ReadUserNamemain();
    // prob();
    return 0;
}