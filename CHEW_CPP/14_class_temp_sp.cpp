#include <iostream>
#include <cstring>
using namespace std;

// 템플릿 관련 정의에는 template <typename T> or template <> 과 같은 선언을 둬서
// 템플릿의 일부 또는 전부를 정의하고 있다는 사실을 컴파일러에게 알려야 한다.

// 템플릿의 정의 부분에 T가 존재한다면 <typename T>과 같은 형태로 설명을 붙여야 하며,
// T가 존재아지 않는다면 <>의 형태로 선언하면 된다.

template <typename T>
class Point {
    private:
        T xpos, ypos;
    public:
        Point(T x=0, T y=0);
        void ShowPosition() const {
            cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
        }
};
template <typename T>
class SimpleDataWrapper {
    private:
        T mdata;
    public:
        SimpleDataWrapper(T data) : mdata(data) {}
        void ShowDataInfo(void) {
            cout<<"Data : "<<mdata<<endl;
        }
};
template <>
class SimpleDataWrapper <char*> {
    private:
        char* mdata;
    public:
        SimpleDataWrapper(char* data) {
            mdata = new char[strlen(data)+1];
            strcpy(mdata, data);
        } 
        void ShowDataInfo(void) {
            cout<<"String : "<<mdata<<endl;
            cout<<"Length : "<<strlen(mdata)<<endl;
        }
        ~SimpleDataWrapper() {
            delete []mdata;
        }
};
template <>
class SimpleDataWrapper <Point<int>> {
    private:
        Point<int> mdata;
    public:
        SimpleDataWrapper(int x, int y) : mdata(x, y) {}
        void ShowDataInfo(void) {
            mdata.ShowPosition();
        }
};
void ClassTemplateSpecialization(void){
    SimpleDataWrapper<int> iwrap(170);
    iwrap.ShowDataInfo();
    // SimpleDataWrapper<char*> swrap("Class Template Specialization");
    // swrap.ShowDataInfo();
    SimpleDataWrapper<Point<int>> pwrap(3, 7);
    pwrap.ShowDataInfo();
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// 전체 특수화가 부분 특수화보다 우선시 됨!
template <typename T1, typename T2>
class MySimple {
    public:
        void WhoAreYou() {
            cout<<"size of T1: "<<sizeof(T1)<<endl;
            cout<<"size of T2: "<<sizeof(T2)<<endl;
            cout<<"typename T1, typename T2"<<endl;
        }
};
template <>
class MySimple <int, double> {
    public:
        void WhoAreYou() {
            cout<<"size of int: "<<sizeof(int)<<endl;
            cout<<"size of double: "<<sizeof(double)<<endl;
            cout<<"int, double"<<endl;
        }
};
template <typename T1>
class MySimple <T1, double> {
    public:
        void WhoAreYou() {
            cout<<"size of T1: "<<sizeof(T1)<<endl;
            cout<<"size of double: "<<sizeof(double)<<endl;
            cout<<"T1, double"<<endl;
        }
};
void ClassTemplatePartialSpecialization(void){
    MySimple<char, double> obj1;
    obj1.WhoAreYou();
    MySimple<int, long> obj2;
    obj2.WhoAreYou();
    MySimple<int, double> obj3;
    obj3.WhoAreYou();
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// 템플릿 클래스 별로 static 멤버변수를 유지하게 된다.
template <typename T>
class SimpleStaticMem {
    private:
        static T mem;
    public:
        void AddMem(T num) { mem += num; }
        void ShowMem() { cout<<mem<<endl; }
};
template <typename T>
T SimpleStaticMem<T>::mem = 0; // Static 멤버의 초기화 문장

void ClassTemplateStaticMem(void){
    SimpleStaticMem<int> obj1;
    SimpleStaticMem<int> obj2;
    obj1.AddMem(2);
    obj2.AddMem(3);
    obj1.ShowMem();
    SimpleStaticMem<long> obj3;
    SimpleStaticMem<long> obj4;
    obj3.AddMem(100);
    obj4.ShowMem();
}
////////////////////////////////////////////////////////////
int main(void){
    ClassTemplateSpecialization();
    ClassTemplatePartialSpecialization();
    ClassTemplateStaticMem();
    return 0;
}