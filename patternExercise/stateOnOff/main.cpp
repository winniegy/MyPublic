#include <iostream>

using namespace std;

class Machine;
class State;


class State
{
public:
    State(Machine* machine) : mMachine(nullptr)
    {
        mMachine = machine;
    }
    virtual void on() = 0;
    virtual void off() = 0;
    virtual ~State() {}
protected:
    Machine* mMachine;
};

class Machine
{
public:
    Machine(State* state) : mState(nullptr)
    {
        state = mState;
    }
    ~Machine()
    {
        delete mState;
    }

    void setState(State* state)
    {
        delete mState;
        mState = state;
    }

    void on()
    {
        mState->on();
    }

    void off()
    {
        mState->off();
    }

protected:
    State* mState;
};




template <typename S>
class OnState : public State
{
public:
    OnState(Machine* machine) : State(machine) {}
    void on()
    {
        cout << "on() called in OnState. No action." << endl;
    }
    void off()
    {
        cout << "off() called in OnState. Change to OffState." << endl;
        mMachine->setState(new S(mMachine));
    }
};

template <typename S>
class OffState : public State
{
public:
    OffState(Machine* machine) : State(machine) {}
    void on()
    {
        cout << "on() called in OffState. Change to OnState." << endl;
        mMachine->setState(new S(mMachine));
    }
    void off()
    {
        cout << "off() called in OffState. No action." << endl;
    }
};


int main(int argc, char *argv[])
{
    std::cout << "Hello World!" << endl;
    void(Machine:: *ptrs[])() = { Machine::off, Machine::on };

    Machine machine(nullptr);
    machine.setState(new OffState<State>(&machine));
    int num;
    while (1)
    {
        std::cout << "Enter 0/1: ";
        cin >> num;
        (machine.*ptrs[num])();
    }
    return 0;

}
