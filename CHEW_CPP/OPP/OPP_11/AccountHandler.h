#ifndef _ACCOUNTHANDLER_H_
#define _ACCOUNTHANDLER_H_
 
#include "Account.h"
#include "BoundCheckArray.h"
 
class AccountHandler {
private:
    BoundCheckArray<Account*> accArr;
    int accNum;
public:
    AccountHandler();
    void ShowMenu(void) const;
    void MakeAccount(void);
    void DepositMoney(void);
    void WithdrawMoney(void);
    void ShowAllAccInfo() const;
    ~AccountHandler();
protected:
    void MakeNormalAccount(void);
    void MakeCreditAccount(void);
};
 
#endif