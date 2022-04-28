//
// Created by Николай on 28.04.2022.
//
#include <iostream>
using namespace std;
class Handler {
public:
    Handler() = default;
    virtual void preProcess() {}
    virtual void postProcess() {}
    virtual void run() = 0;
    virtual bool accessAllowed(string username){
        return true;
    }
    virtual ~Handler() = default;
};

// Должен не работать, так как не предоставляет run
class BadHandler : public Handler {
};

class DummyHandler : public Handler {
public:
    void run() {
        cout << "DummyHandler runs" << endl;
    }
};

int main() {
    Handler* h = new BadHandler();
}