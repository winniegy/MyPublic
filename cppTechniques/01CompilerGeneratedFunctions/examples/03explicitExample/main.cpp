#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    A(int i) : mI(i){}
    //explicit A(int i) : mI(i){}
    int mI;
};

void printA(A a) {
    std::cout << a.mI << std::endl;
};

int main() {
    A tmp(1);
    printA(tmp);
    printA(2); // compilation error if explicit
    return 0;
}
