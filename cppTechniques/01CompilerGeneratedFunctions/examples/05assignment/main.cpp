#include "operation.h"
#include <utility>

Operation fun(Operation a) {
    return a;
}

int main()
{
    using namespace std;
    Operation a("secretA");
    Operation b("secretB");

    cout << "========= a=b =========" << endl;
    a = b;

    cout << "========= b=b =========" << endl;
    b = b;  //?

    cout << "=========  =========" << endl;
    Operation c = fun(Operation("SecretFun"));

    cout << "========= swap(a,c) =========" << endl;
    swap(a, c);

    return 0;
}





