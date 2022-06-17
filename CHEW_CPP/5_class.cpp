#include <iostream>
using namespace std;

class FruitSeller{
    private:
        int APPLE_PRICE;
        int numOfApples;
        int myMoney;
    public:
        void InitMembers(int price, int num, int money);
        int SaleApples(int money);
        void ShowSalesResult();
};
void FruitSeller::InitMembers(int price, int num, int money){
    APPLE_PRICE = price;
    numOfApples = num;
    myMoney = money;
}
int FruitSeller::SaleApples(int money){
    int num = money / APPLE_PRICE;
    numOfApples = num;
    myMoney = money;
    return num;
}
void FruitSeller::ShowSalesResult(){
    cout<<"left apple: "<<numOfApples<<endl;
    cout<<"left money: "<<myMoney<<endl<<endl;
}

class FruitBuyer{
    // private
    int myMoney;
    int numOfApples;
    public:
        void InitMembers(int money);
        void BuyApples(FruitSeller &seller, int money);
        void ShowBuyResult();
};
void FruitBuyer::InitMembers(int money){
    myMoney = money;
    numOfApples = 0;
}
void FruitBuyer::BuyApples(FruitSeller &seller, int money){
    numOfApples += seller.SaleApples(money);
    myMoney -= money;
}
void FruitBuyer::ShowBuyResult(){
    cout<<"num of apple: "<<numOfApples<<endl;
    cout<<"my left money: "<<myMoney<<endl<<endl;
}

int main(void){
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    
    // Message Passing
    // giving message from a class to another class
    buyer.BuyApples(seller, 2000);

    cout<<"seller's point"<<endl;
    seller.ShowSalesResult();
    cout<<"buyer's point"<<endl;
    buyer.ShowBuyResult();
    return 0;
}