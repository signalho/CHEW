#include <iostream>
using namespace std;

// Operator Overloading by 'member function'
class Point {
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        void ShowPosition() const {
            cout<<'['<<xpos<<","<<ypos<<']'<<endl;
        }
        Point operator+ (const Point &ref) {
            Point pos(xpos+ref.xpos, ypos+ref.ypos);
            return pos;
        }
};
void OpOverex(void){
    Point pos1(3,4);
    Point pos2(10,20);

    // pos1+pos2 <-> pos1.operator+(pos2)
    Point pos3 = pos1 + pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
}
////////////////////////////////////////////////////////////
// Operator Overloading by 'global function'
class Pointt {
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        void ShowPosition() const {
            cout<<'['<<xpos<<","<<ypos<<']'<<endl;
        }
        friend Point operator+ (const Point &pos1, const Point &pos2);
};
Point operator+ (const Point &pos1, const Point &pos2) {
    Point pos(pos1.xpos+pos2.xpos, pos1.ypos+pos2.ypos);
    return pos;
}
void OpOverex2(void){
    Point pos1(3,4);
    Point pos2(10,20);

    // pos1+pos2 <-> operator+(pos1, pos2)
    Point pos3 = pos1 + pos2;

    pos1.ShowPosition();
    pos2.ShowPosition();
    pos3.ShowPosition();
}
////////////////////////////////////////////////////////////
// One Operand Overloading
class Pointtt {
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        void ShowPosition() const {
            cout<<'['<<xpos<<","<<ypos<<']'<<endl;
        }
        // operator is overloaded by 'member' function
        Point& operator++() {
            xpos+=1;
            ypos+=1;
            return *this;
        }
        // operator is overloaded by 'global' function
        friend Point& operator-- (Point &ref);
};
Point operator-- (Point &ref) {
    ref.xpos-=1;
    ref.ypos-=1;
    return ref;
}
void OpOverex3(void){
    Point pos1(3,4);
    ++pos;
    pos.ShowPosition();
    --pos;
    pos.ShowPosition();

    ++(++pos);
    pos.ShowPosition();
    --(--pos);
    pos.ShowPosition();
}
////////////////////////////////////////////////////////////
int main(void){
    OpOverex();
    OpOverex2();
    OpOverex3();
    return 0;
}