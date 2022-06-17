#include <stdio.h>
#include <string.h>

typedef int CAL_TYPE; // used when type varies
///////////////STRUCT POINTER/////////////////////////////
struct point{
    CAL_TYPE xpos;
    CAL_TYPE ypos;
};
int structpointer(void){
    struct point pos1={1,2};
    struct point pos2={100,200};
    struct point *pptr=&pos1;

    (*pptr).xpos += 4;
    (*pptr).ypos += 5;
    printf("[%d %d] \n", pptr->xpos, pptr->ypos);

    pptr=&pos2;
    pptr->xpos += 1;
    pptr->ypos += 2;
    printf("[%d %d] \n", (*pptr).xpos, (*pptr).ypos); // SAME!!!!
    printf("[%d %d] \n",   pptr->xpos,   pptr->ypos); // SAME!!!!
    return 0;
}
//////////////////////////////////////////////////////////

////////////////TYPEDEF & STRUCTinFUNC////////////////////
typedef struct person{
    char name[20];
    char phonenum[20];
    int age;
} Person;

void ShowPersonInfo(Person man){
    printf("name: %s \n", man.name);
    printf("phnm: %s \n", man.phonenum);
    printf("age : %d \n", man.age);
}
Person ReadPerosonInfo(void){
    Person man = {"jung", "1", 24};
    Person *pptr = &man;
    // pptr -> name = "jung";       // gets error since char is literal
    strcpy(man.name, "jjj");        // use strcpy with string.h instead
    strcpy(pptr -> name, "literal");
    pptr -> age = 25;
    return man;
}
int getpersoninfo(void){
    Person man = ReadPerosonInfo();
    ShowPersonInfo(man);
    return 0;
}
//////////////////////////////////////////////////////////

/////////////////STRUCT in STRUCT/////////////////////////
typedef struct position{
    int xpos;
    int ypos;
}Position;
typedef struct circle{
    Position cen;
    double rad;
}Circle;
void ShowCircleInfo(Circle *cptr){
    printf("[%d %d] \n", (cptr->cen).xpos,(cptr->cen).ypos);
    printf("radius : %g \n", cptr->rad);   
}
int getcircleinfo(void){
    Circle c1={{1, 2}, 3.5};
    Circle c2={2, 4, 3.9};
    ShowCircleInfo(&c1);
    ShowCircleInfo(&c2);
    return 0;
}
//////////////////////////////////////////////////////////
int main(void){
    structpointer();
    getpersoninfo();
    getcircleinfo();
    return 0;
}