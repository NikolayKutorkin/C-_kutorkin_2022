//
// Created by Николай on 18.02.2022.
//
class C1 {
protected:
    int a;
};
class C2 : private C1 {
    C2() {
        a = 42;
    }
};
