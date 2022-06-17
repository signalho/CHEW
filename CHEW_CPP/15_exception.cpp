#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// try와 catch는 하나의 문장이며 항상 이어서 등장해야 한다.
// 중간에 다른 문장이 오면 안된다.


void HandlingExceptionTryCatch(void){
    int num1, num2;
    cout<<"두 개의 숫자 입력: ";
    cin>>num1>>num2;

    try {
        if(num2==0)
            // throw가 실행되는 순간 catch로 넘어가게 된다.
            throw num2;
        cout<<"나눗셈의 몫: "<<num1/num2<<endl;
        cout<<"나눗셈의 나머지: "<<num1%num2<<endl;
    }
    // throw에 할당된 변수가 expn으로 들어가게 된다.
    catch(int expn) {
        cout<<"제수는 "<<expn<"이 될 수 없습니다"<<endl;
        cout<<"프로그램을 다시 실행하세요."<<endl;
    }
    cout<<"end of main"<<endl;
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// 예외가 처리되지 않으면, 예외가 발생한 함수를 호출한 영역으로 예외 데이터가 전달된다.
int StoI(char* str) {
    int len=strlen(str);
    int num = 0;
    for(int i=0; i<len; i++) {
        if(str[i]<'0' || str[i]>'9')
            throw str[i];
        num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7')))
    }
    return num;
}
void DiffHandlingPosition(void) {
    char str1[100];
    char str2[200];

    while(1) {
        cout<<"두개의 숫자 입력: ";
        cin>>str1>>str2;
        try {
            cout<<str1<<" + "<<str2<<" = "<<StoI(str1)+StoI(str2)<<endl;
            break;
        }
        catch (char ch) {
            cout<<"문자 "<<ch<<"가 입력되었습니다."<<endl;
            cout<<"재입력 하세요."<<endl<<endl;
        }
    }
    cout<<"프로그램 종료"<<endl;
}
////////////////////////////////////////////////////////////
int main(void){
    HandlingExceptionTryCatch();
    DiffHandlingPosition();
    return 0;
}