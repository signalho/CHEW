#include <iostream>
using namespace std;

// add c and remove .h from C library
#include <cstring>

////////////////////////////////////////////////////////////////
// cpp use 'new', 'delete' instead of 'malloc', 'free'
// Type * pointer = new Type;
// delete pointer;
char *StrAdr(int len){
    // char *str=(char*)malloc(sizeof(char)*len);
    char *str = new char[len];
    return str;
}
void StrAdrmain(void){
    char *str = StrAdr(20);
    strcpy(str, "I am so happy");
    cout<<str<<endl;
    // free(str);
    delete []str;
}
////////////////////////////////////////////////////////////////
typedef struct __Point{
    int xpos;
    int ypos;
} Point;
Point &PntAdder(const Point &p1, const Point &p2){
    Point *pptr = new Point;
    pptr->xpos = p1.xpos + p2.xpos;
    pptr->ypos = p1.ypos + p2.ypos;
    return *pptr;
}
int PntAddermain(void){
    Point *pptr1 = new Point;
    pptr1->xpos=3;
    pptr1->ypos=30;
    Point *pptr2 = new Point;
    pptr2->xpos=5;
    pptr2->ypos=1;

    Point &pref = PntAdder(*pptr1, *pptr2);
    cout<<"["<<pref.xpos<<","<<pref.ypos<<"]"<<endl;

    delete pptr1; delete pptr2 ; delete &pref;
    return 0;
}
////////////////////////////////////////////////////////////////
int main(void){
    StrAdrmain();
    PntAddermain();
    return 0;
}