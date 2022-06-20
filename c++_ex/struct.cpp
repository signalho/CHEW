#include <stdio.h>

/* ex1
struct Human {
    int age;    
    int height;
    int weight;
};          
int main() {
    struct Human Psi;

    Psi.age = 99;
    Psi.height = 185;
    Psi.weight = 80;

    printf("Psi 에 대한 정보 \n");
    printf("나이   : %d \n", Psi.age);
    printf("키     : %d \n", Psi.height);
    printf("몸무게 : %d \n", Psi.weight);
    return 0;
}
*/

/* ex2
char copy_str(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}
struct Books {
    char name[30];
    char auth[30];
    char publ[30];
    int borrowed; //variable init XX ex) int borrowed = 1 XXX
};
int main() {
    struct Books Harry_Potter;

    copy_str(Harry_Potter.name, "Harry Potter");
    copy_str(Harry_Potter.auth, "J.K. Rolling");
    copy_str(Harry_Potter.publ, "Scholastic");
    Harry_Potter.borrowed = 0;

    printf("책 이름 : %s \n", Harry_Potter.name);
    printf("저자 이름 : %s \n", Harry_Potter.auth);
    printf("출판사 이름 : %s \n", Harry_Potter.publ);

    return 0;
}
*/

/* ex3
struct test {
    int a, b;
};
int main() {
    struct test st;
    struct test* ptr;
    ptr = &st;
    ptr->a = 1;  // (*ptr).a = 1; st.a = 1; all same func
    ptr->b = 2;
    printf("st 의 a 멤버 : %d \n", st.a);
    printf("st 의 b 멤버 : %d \n", st.b);
    return 0;
}
*/