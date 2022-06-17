#include <iostream>
using namespace std;

class Sinivelcap{
    public:
        // Using 'const' -> no member variable modifies concerned in this func
        void Take() const{
            cout<<"no runny nose"<<endl;
        }
};
class Sneezecap{
    public:
        // Using 'const' -> no member variable modifies concerned in this func
        void Take() const{
            cout<<"no sneeze"<<endl;
        }
};
class Snufflecap{
    public:
        // Using 'const' -> no member variable modifies concerned in this func
        void Take() const{
            cout<<"booms nose"<<endl;
        }
};
class CONTAC600{
    private:
        Sinivelcap sin;
        Sneezecap sne;
        Snufflecap snu;
    public:
        // Encapsuling process
        // User doesn't need to consider the order/members
        void Take() const{
            sin.Take();
            sne.Take();
            snu.Take();
        }
};
class ColdPatient{
    public:
        void TakeCONTAC600(const CONTAC600 &cap) const{
            cap.Take();
        }
};
////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
int main(void){
    CONTAC600 cap;
    ColdPatient sufferer;
    sufferer.TakeCONTAC600(cap);
    return 0;
}