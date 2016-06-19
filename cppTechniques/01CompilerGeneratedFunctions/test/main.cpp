#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    A() : pStr(nullptr) {
        pStr = new std::string("I am class A.");
    }
    ~A() {
        delete pStr;
    }

private:
    std::string* pStr;
};


int main() {

    return 0;
}
