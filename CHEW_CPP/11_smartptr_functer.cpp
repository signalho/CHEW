#include <iostream>
using namespace std;

// 객체의 소멸을 위한 delete 연산 등이 자동으로 이뤄지는 스마트 포인터!
// 보통 라이브러리로 만들어진 스마트 포인터를 활용한다.
class Point {
    private:
        int xpos, ypos;
    public:
        Point(int x=0, int y=0) : xpos(x), ypos(y) {
            cout<<"Point 생성"<<endl;
        }
        ~Point() {
            cout<<"Point 소멸"<<endl;
        }
        void SetPos(int x, int y) {
            xpos=x;
            ypos=y;
        }
        friend ostream& operator<<(ostream& os, const Point& pos);
};
ostream& operator<<(ostream& os, const Point& pos) {
    os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
    return os;
}
class SmartPtr {
    private:
        Point* posptr;
    public:
        SmartPtr(Point* ptr) : posptr(ptr) {}
        Point& operator*() const { return * posptr; }
        Point* operator->() const { return posptr; }
        // 생성자의 인자로 전달되는 주소 값이 new 연산에 의해 동적 할당된 객체의 주소 값이라는 가정이 포함됨.
        ~SmartPtr() { delete posptr; }
};
void SmartPointer(void){
    SmartPtr sptr1(new Point(1,2));
    SmartPtr sptr2(new Point(3,4));
    SmartPtr sptr3(new Point(5,6));
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;

    sptr1->SetPos(10,20);
    sptr2->SetPos(30,40);
    sptr3->SetPos(50,60);
    cout<<*sptr1;
    cout<<*sptr2;
    cout<<*sptr3;
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// 객체를 함수처럼 사용하는 Functor! (혹은 함수처럼 동작하는 클래스를 Functor!)
class SortRule {
public:
    virtual bool operator()(int num1, int num2) const = 0;
};
class AscendingSort :public SortRule {
public:
    bool operator()(int num1, int num2) const {
        if (num1 > num2)
            return true;
        else
            return false;
    }
};
class DescendingSort :public SortRule {
public:
    bool operator()(int num1, int num2) const {
        if (num1 < num2)
            return true;
        else
            return false;
    }
};
class DataStorage {
private:
    int* arr;
    int idx;
    const int MAX_LEN;
 
public:
    DataStorage(int arrlen) : idx(0), MAX_LEN(arrlen) {
        arr = new int[MAX_LEN];
    }
    void AddData(int num) {
        if (MAX_LEN <= idx) {
            cout << "더 이상 저장이 불가능합니다." << endl;
            return;
        }
        arr[idx++] = num;
    }
    void ShowAllData() {
        for (int i = 0; i < idx; ++i)
            cout << arr[i] << ' ';
        cout << endl;
    }
    void SortData(const SortRule& functor) {
        for (int i = 0; i < (idx - 1); ++i) {
            for (int j = 0; j < (idx - 1) - i; ++j) {
                if (functor(arr[j], arr[j + 1])) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
};
void SortFunctor(void) {
    DataStorage storage(5);
    storage.AddData(40);
    storage.AddData(30);
    storage.AddData(50);
    storage.AddData(20);
    storage.AddData(10);
 
    storage.SortData(AscendingSort());
    storage.ShowAllData();
 
    storage.SortData(DescendingSort());
    storage.ShowAllData();
}
////////////////////////////////////////////////////////////
int main(void){
    SmartPointer();
    SortFunctor();
    return 0;
}