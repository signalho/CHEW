#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Max(T a, T b) {
    return a > b ? a : b;
}
template <>
// char * Max<char*>(char* a, char* b)
char * Max(char* a, char* b){
    cout<<"char* Max<<char*>(char* a, char* b)"<<endl;
    return strlen(a) > strlen(b) ? a : b;
}
template <>
// const char * Max<const char*>(const char* a, const char* b)
const char * Max(const char* a, const char* b){
    cout<<"const char* Max<<const char*>(const char* a, const char* b)"<<endl;
    return strcmp(a, b) > 0 ? a : b;
}
void SpecialFunctionTemplate(void){
    cout<< Max(11,15)<<endl;
    cout<< Max('T','Q')<<endl;
    cout<< Max("Simple","Best")<<endl;
    
    char str1[] = "Simple";
    char str2[] = "Best";
    cout<< Max(str1,str2)<<endl;
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// 클래스 템플릿 기반의 객체생성에는 반드시 자료형 정보 명시!!!
// ex. Point<int> or Point<double>
template <typename T>
class Point {
    private:
        T xpos, ypos;
    public:
        Point(T x=0, T y=0);
        void ShowPosition() const;
};
template <typename T>
Point<T>::Point(T x, T y) : xpos(x), ypos(y) {}

template <typename T>
void Point<T>::ShowPosition() const {
    cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
}

void PointClassTemplate(void){
    Point<int> pos1(3,4);
    pos1.ShowPosition();

    Point<double> pos2(2.4, 3.6);
    pos2.ShowPosition();

    Point<char> pos3('P','F');
    pos3.ShowPosition();
}
////////////////////////////////////////////////////////////
int main(void){
    SpecialFunctionTemplate();
    PointClassTemplate();
    return 0;
}