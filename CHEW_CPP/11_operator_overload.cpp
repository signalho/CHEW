#include <iostream>
#include <cstdlib>
using namespace std;

// 생선자 내에서 동적 할당 하는 경우, 디폴트 대입 연산자는 직접 대입 연산자를 정의해야 함.
// 1. 깊은 복사를 진행하도록 한다.
// 2. 깊은 복사에 앞서 메모리 해제 과정을 거친다.
class First {
    private: 
        int num1, num2;
    public:
        First(int n1=0, int n2=0) : num1(n1), num2(n2) {}
        void ShowData() { cout<<num1<<' '<<num2<<endl;}
        First& operator=(const First& ref) {
            cout<<"First& operator=()"<<endl;
            num1=ref.num1;
            num2=ref.num2;
            return *this;
        }
};
class Second : public First {
    private: 
        int num3, num4;
    public:
        Second(int n1, int n2, int n3, int n4) : First(n1, n2), num3(n3), num4(n4) {}
        void ShowData() { 
            First::ShowData();
            cout<<num3<<' '<<num4<<endl;
        }
        Second& operator=(const Second& ref) {
            cout<<"Second& operator=()"<<endl;
            // 기초 클래스의 대입 연산자를 호출하지 않으면, 멤버 대 멤버의 복사 대상에서 제외된다.
            // 이 행이 없으면 n1, n2는 0, 0에서 안바뀐다.
            First::operator=(ref);
            num3=ref.num3;
            num4=ref.num4;
            return *this;
        }
};
void InheritAssignOperation(void){
    Second ssrc(111,222,333,444);
    Second scpy(0,0,0,0);
    scpy=ssrc;
    scpy.ShowData();
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
class BoundCheckIntArray{
    private:
        int* arr;
        int arrlen;
        BoundCheckIntArray(const BoundCheckIntArray& arr) {}
        BoundCheckIntArray& operator=(const BoundCheckIntArray& arr) {}
    public:
        BoundCheckIntArray(int len) :arrlen(len) {arr=new int[len];}
        int& operator[] (int idx){
            if(idx < 0 || idx >= arrlen) {
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int operator[] (int idx) const {
            if(idx < 0 || idx >= arrlen) {
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrLen() const {return arrlen; }
        ~BoundCheckIntArray() {delete []arr; }
};
void ShowAllData(const BoundCheckIntArray& ref){
    int len = ref.GetArrLen();
    for(int idx=0; inx<len; idx++)
        // const 참조자를 이용한 연산이므로 int operator[] (int idx) const 이 호출됨.
        cout<<ref[idx]<<endl;
}
void StableConstArraySolu(void){
    BoundCheckIntArray arr(5);
    for(int i=0; i<5; i++){
        // const 참조자를 이용하지 않은 연산이므로 int& operator[] (int idx) 이 호출됨.
        arr[i] = (i+1)*11;
    }
    ShowAllData(arr);
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
class Point {
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {}
        friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}
typedef Point * POINT_PTR;

class BoundCheckPointPtrArray {
    private:
        POINT_PTR * arr;
        int arrlen;
        BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) {}
        BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) {}
    public:
        BoundCheckPointPtrArray(int len) :arrlen(len) {arr=new POINT_PTR[len];}
        POINT_PTR& operator[] (int idx){
            if(idx < 0 || idx >= arrlen) {
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        POINT_PTR operator[] (int idx) const {
            if(idx < 0 || idx >= arrlen) {
                cout<<"Array index out of bound exception"<<endl;
                exit(1);
            }
            return arr[idx];
        }
        int GetArrLen() const {return arrlen; }
        ~BoundCheckPointPtrArray() {delete []arr; }
};
void StablePointArray(void){
    BoundCheckPointPtrArray arr(3);
    // 객체의 주소값 저장하므로 깊은or얕은 복사 고민할 필요 없음!!!
    arr[0] = new Point(3,4);
    arr[1] = new Point(5,6);
    arr[2] = new Point(7,8);
    for(int i=0; i<arr.GetArrLen(); i++) {
        cout<<*(arr[i]);
    }
    delete arr[0];
    delete arr[1];
    delete arr[2];
}
////////////////////////////////////////////////////////////
int main(void){
    InheritAssignOperation();
    StableConstArraySolu();
    StablePointArray();
    return 0;
}