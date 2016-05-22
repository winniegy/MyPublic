#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>
#include <utility>
#include <string>

using namespace std;

class Operation {
private:
    string* pSecret;

    Operation() : pSecret(nullptr) {
        cout << "default constructor called." << endl;
    }

public:
    explicit Operation(const string& secret) : pSecret(new string(secret)) {
        cout << "single argument constructor called." << endl;
    }

    Operation(const Operation& rhs) : pSecret(new string(*rhs.pSecret)) {
        cout << "copy constructor called." << endl;
    }

    ~Operation() {
        cout << "destructor constructor called." << endl;
        delete pSecret;
    }

    /*
    // version 1
    Operation& operator=(const Operation& rhs) {
        cout << "assignment operator called." << endl;
        cout << "Old secret: " << *pSecret << endl;
        delete pSecret;
        pSecret = new string(*rhs.pSecret);
        cout << "new secret: " << *pSecret << endl;
        return *this;
    }
    */

    /*
    // version 2, identity test
    Operation& operator=(const Operation& rhs) {
        if (this == &rhs) {
            cout << "same operation, secret: "<< *pSecret << endl;
            return *this;
        }

        cout << "assignment operator called." << endl;
        cout << "Old secret: " << *pSecret << endl;

        delete pSecret;
        pSecret = new string(*rhs.pSecret);
        cout << "new secret: " << *pSecret << endl;

        return *this;
    }
    */

    /*
    //version 3: Strong exception safety
    Operation& operator=(const Operation& rhs) {
        cout << "assignment operator called." << endl;
        cout << "Old secret: " << *pSecret << endl;

        string* pStr = pSecret;
        pSecret = new string(*rhs.pSecret);
        delete pStr;
        cout << "new secret: " << *pSecret << endl;

        return *this;
    }
    */


    //version 4: Copy-swap idiom
    friend void swap(Operation& lhs, Operation& rhs)
    {
        cout << "swap" << endl;
        swap(lhs.pSecret, rhs.pSecret);
    }

    Operation& operator=(Operation rhs) {
        cout << "assignment operator called." << endl;
        cout << "Old secret: " << *pSecret << endl;

        swap(*this, rhs);
        cout << "new secret: " << *pSecret << endl;

        return *this;
    }

    //move constructor C++ 11
    /*
    Operation(Operation&& rhs) : Operation() {
        cout << "move constructor called." << endl;
        swap(*this, rhs);
    }
    */
    Operation(Operation&& rhs) : pSecret(std::move(rhs.pSecret)) {

    }
};


#endif // OPERATION_H
