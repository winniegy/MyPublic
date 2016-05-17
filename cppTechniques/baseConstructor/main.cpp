#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Other {};
class A {
public:
    A() :
        mInt(0),
        mStr("A"),
        mOther(NULL) // or 0, nullptr for C++
    {
        mVec.reserve(5);  //reserve 5 element of int for mVec
        cout << mVec.capacity() << endl;
    }

private:
    int mInt;
    std::string mStr;
    std::vector<int> mVec;
    Other* mOther;
};

int main() {
    A a;
    return 0;
}
