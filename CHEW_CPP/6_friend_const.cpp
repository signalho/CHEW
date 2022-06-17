#include <iostream>
using namespace std;

// 'const' objective
// prefer to declare 'const' if
// the function doesn't modify any member variables
class SoSimple{
    private:
        int num;
    public:
        SoSimple(int num) : num(n) {}
        SoSimple& AddNum(int n) {
            num += m;
            return *this;
        }
        void ShowData() const{
            cout<<"num : "<<num<<endl;
        }
};
void Soconst(void){
    // Making 'const' object
    const SoSimple obj(7);

    // Can't apply because AddNum is not 'const'
    // obj.AddNum(20);

    // Can apply because ShowData is 'const'
    obj.ShowData();
}
////////////////////////////////////////////////////////////
// Declaring 'friend'
// give access to private members between classes
// be careful to use this!!!
class Point;
class PointOP{
    private:
        int opcnt;
    public:
        PointOP() : opcnt(0) {}
        Point PointAdd(const Point&, const Point&);
        Point PointSub(const Point&, const Point&);
        ~PointOP(){
            cout<<"Operation times: "<<opcnt<<endl;
        }
};
class Point{
    private:
        int x;
        int y;
    public:
        Point(const int &xpos, const int &ypos) : x(xpos), y(ypos) {}
        friend Point PointOP::PointAdd(const Point&, const Point&);
        friend Point PointOP::PointSub(const Point&, const Point&);
        friend void ShowPointPos(const Point&);
};
Point PointOP::PointAdd(const Point& pnt1, const Point& pnt2){
    opcnt++;
    return Point(pnt1.x+pnt2.x,pnt1.y+pnt2.y);
}
Point PointOP::PointSub(const Point& pnt1, const Point& pnt2){
    opcnt++;
    return Point(pnt1.x-pnt2.x,pnt1.y-pnt2.y);
}
void ShowPointPos(const Point& pos){
    cout<<"x: "<<pos.x<<", ";
    cout<<"y: "<<pos.y<<endl;
}
void Sofriend(void){
    Point pos1(1,2);
    Point pos2(2,4);
    PointOP op;
    ShowPointPos(op.PointAdd(pos1,pos2));
    ShowPointPos(op.PointSub(pos2,pos1));
}
////////////////////////////////////////////////////////////
int main(void){
    Soconst();
    Sofriend();
    return 0;
}