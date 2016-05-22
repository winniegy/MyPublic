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

    a = b;

    b = b;  //?

    Operation c = fun(Operation("SecretFun"));

    swap(a, c);

    return 0;
}





