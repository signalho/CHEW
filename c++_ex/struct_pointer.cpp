// 포인터 갖고 놀기
/*
#include <stdio.h>
struct TEST {
    int c;
};

int main() {
    struct TEST t;
    struct TEST* pt = &t;

    //pt 가 가리키는 구조체 변수의 c 멤버의 값을 0 으로 한다
    (*pt).c = 0;

    printf("t.c : %d \n", t.c);

    // pt 가 가리키는 구조체 변수의 c 멤버의 값을 1 으로 한다
    pt->c = 1;

    printf("t.c : %d \n", t.c);

    return 0;
}
*/

/* 인자로 제대로 전달하기
#include <stdio.h>
struct TEST {
    int age;
    int gender;
};
int set_human(struct TEST* a, int age, int gender) {
    a->age = age;
    a->gender = gender;

    return 0;
}
int main() {
    struct TEST human;

    set_human(&human, 10, 1);

    printf("AGE : %d // Gender : %d ", human.age, human.gender);
    return 0;
}
*/

/* 살짝 업그레이드
#include <stdio.h>
struct TEST {
    int age;
    int gender;
    char name[20];
};
int set_human(struct TEST* a, int age, int gender, const char* name) {
    a->age = age;
    a->gender = gender;
    copy_str(a->name, name);

    return 0;
}
char copy_str(char* dest, const char* src) {
    while (*src) {
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}
int main() {
    struct TEST human;

    set_human(&human, 10, 1, "Lee");

    printf("AGE : %d // Gender : %d // Name : %s \n", human.age, human.gender,
        human.name);
    return 0;
}
*/

/* 구조체 안의 구조체
#include <stdio.h>
struct employee {
    int age;
    int salary;
};
struct company {
    struct employee data;
    char name[10];
};
int main() {
    struct company Kim;

    Kim.data.age = 31;
    Kim.data.salary = 3000000;

    printf("Kim's age : %d \n", Kim.data.age);
    printf("Kim's salary : %d$/year \n", Kim.data.salary);

    return 0;
}
*/

/* 멤버를 쉽게 초기화 하기
#include <stdio.h>
int Print_Status(struct HUMAN human);
struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

int main() {
    struct HUMAN Adam = { 31, 182, 75, 0 };
    struct HUMAN Eve = { 27, 166, 48, 1 };

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(struct HUMAN human) {
    if (human.gender == 0) {
        printf("MALE \n");
    }
    else {
        printf("FEMALE \n");
    }

    printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height,
        human.weight);

    if (human.gender == 0 && human.height >= 180) {
        printf("HE IS A WINNER!! \n");
    }
    else if (human.gender == 0 && human.height < 180) {
        printf("HE IS A LOSER!! \n");
    }

    printf("------------------------------------------- \n");

    return 0;
}
*/

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

