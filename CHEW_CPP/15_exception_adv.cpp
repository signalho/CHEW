#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

// 한 try 블록에서 여러 예외 상황이 있을 수 있고, 각 상황별 자료형이 다를 수 있다.
// 이에 따라 catch 블록이 여러개가 될 수 있다.

int StoI(char* str) {
    int len=strlen(str);
    int num = 0;

    if(len!=0 && str[0]=='0')
        // 0 으로 시작하는 숫자들에 대해 예외 추가! (사용자 실수이므로)
        throw 0;

    for(int i=0; i<len; i++) {
        if(str[i]<'0' || str[i]>'9')
            // 사용자의 실수!!
            throw str[i];
        num += (int)(pow((double)10, (len-1)-i) * (str[i]+(7-'7')))
    }
    return num;
}
void CatchList(void) {
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
        catch (int expn) {
            if(expn == 0)
                cout<<"0으로 시작하면 안됨."<<endl;
            // 잘못 입력된 값이 0이 아닐 경우!! (임의로 만들어 놓음)
            else
                cout<<"뭔가 이상함."<<endl;
            cout<<"재입력 하세요."<<endl<<endl;
        }
    }
    cout<<"프로그램 종료"<<endl;
}
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// 예외 클래스와 예외 객체의 예시이다.
class DepositException {
    private:
        int reqDep;
    public:
        DepositException(int money) : reqDep(money) {}
        void ShowExceptionReason() {
            cout<<"[예외 메시지: "<<reqDep<<"는 입금불가"<<endl;
        }
};
class Account {
    privat:
        char accNum[50];
        int balance;
    public:
        Account(char* acc, int money) : balance(money) {
            strcpy(accNum, acc);
        }
        // 여기에 예외 처리를 했다!
        void Deposit(int money) throw (DepositException) {
            if(money < 0) {
                DepositException expn(money);
                throw expn;
            }
            balance += money;
        }
        void Withdraw(int money) throw (WithdrawException) {
            if(money > balance) {
                WithdrawException expn(balance);
                throw expn;
            }
            balance -= money;
        }
        void ShowMyMoney() {
            cout<<"잔고: "<<balance<<endl<<endl;
        }
};
void ATMSim(void) {
    Account myAcc("56789-827120", 5000);
    try {
        myAcc.Deposit(2000);
        myAcc.Deposit(-300);
    }
    catch(DepositException &expn) {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();

    try {
        myAcc.Withdraw(3500);
        myAcc.Withdraw(4000);
    }
    catch(WithdrawException &expn) {
        expn.ShowExceptionReason();
    }
    myAcc.ShowMyMoney();
}
////////////////////////////////////////////////////////////
int main(void){
    CatchList();
    ATMSim();
    return 0;
}