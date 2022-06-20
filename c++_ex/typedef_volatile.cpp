/*
// typedef 의 이용 
// typedef (이름을 새로 부여하고자 하는 타입) (새로 준 타입의 이름)
// struct HUMAN a; 랑 
// Human a; 랑 같아짐

#include <stdio.h>
struct HUMAN {
    int age;
    int height;
    int weight;
    int gender;
};

typedef struct HUMAN Human;  //이 부분이 중요
int Print_Status(Human human);
int main() {
    Human Adam = { 31, 182, 75, 0 };
    Human Eve = { 27, 166, 48, 1 };

    Print_Status(Adam);
    Print_Status(Eve);
}

int Print_Status(Human human) {
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
#include <stdio.h>
int add(int a, int b) { return a + b; }

// CAL_TYPE의 자료형을 맘대로 위에서 바꾸기 가능
typedef int CAL_TYPE;

// int (*ptr)(int, int) = add;
// Padd ptr = add; 같아짐
typedef int (*Padd)(int, int);

typedef int Arrays[10];

int main() {
  CAL_TYPE a = 10;
  Arrays arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
  Padd ptr = add;
  printf("a : %d \n", a);
  printf("arr[3] : %d \n", arr[3]);
  printf("add(3, 5) : %d \n", ptr(3, 5));
  return 0;
}
*/

/* 
#include <stdio.h>
typedef struct SENSOR {
  // 감지 안되면 0, 감지되면 1 이다.
int sensor_flag;
int data;
} SENSOR;

int main() {
    volatile SENSOR* sensor; // sensor 값은 계속 변동을 할 수 있으니 최적화 작업을 수행하지 마라!
    // 최적화 작업을 수행하게 되면 0으로 계속 인식하게 됨
    // 값이 감지되지 않는 동안 계속 무한 루프를 돈다
    while (!(sensor->sensor_flag)) {
    }
    printf("Data : %d \n", sensor->data);
}
*/

