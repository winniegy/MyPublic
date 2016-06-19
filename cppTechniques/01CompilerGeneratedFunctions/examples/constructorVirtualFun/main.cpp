#include <iostream>

using namespace std;

class Operation {
public:
    Operation() {
        init();
    }
    ~Operation() {}
protected:
    void init() {
        logOperation();
    }
    virtual void logOperation() = 0;
};

class ReadOperation : public Operation {
protected:
    void logOperation() {
        cout << "Log read operation created." << endl;
    }
};

class WriteOperation : public Operation {
protected:
    void logOperation() {
        cout << "Log write operation created." << endl;
    }
};


int main()
{
    Operation* operation = new ReadOperation();
    return 0;
}
