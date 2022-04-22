//
// Created by Николай on 16.04.2022.
//
#include <iostream>
using namespace std;
class VectorN {
protected:
    int* v;
    unsigned int size;
public:
    // Конструктор вектора размерности n
    VectorN()= default;
    VectorN(unsigned int n) {
        v = new int[n];
        size = n;
    }


    // Деструктор
    ~VectorN() {
        delete v;
    }

    // Получение размерности вектора
    unsigned getSize() const {
        return size;
    }

    // Получение значения i-ой координаты вектора,
    // i находится в диапазоне от 0 до n-1
    int getValue(unsigned int i) const {
        return v[i];
    }

    // Задание значения i-ой координаты вектора равным value,
    // i находится в диапазоне от 0 до n-1
    void setValue(unsigned int i, int value) {
        v[i] = value;
    }

    bool operator== (VectorN& v2) const{
        for(unsigned i = 0; i < this->size; i++) {
            if (v2.getValue(i) != v[i]) return false;
        }
        return true;
    }

    bool operator!= (VectorN v2) const{
        return !(*this == v2);
    }

    VectorN operator+ (VectorN& v2) const{
        VectorN v3(size);
        for(unsigned i = 0; i < size; i++) {
            v3.setValue(i, v[i] + v2.getValue(i));
        }
        return v3;
    }

    VectorN operator* (const int a) const{
        VectorN v2(size);
        for(unsigned i = 0; i < size; i++) {
            v2.setValue(i, v[i] * a);
        }
        return v2;
    }
};

VectorN operator* (int a, const VectorN& v) {
    VectorN v2(v.getSize());
    for (unsigned i = 0; i < v.getSize(); i++) {
        v2.setValue(i, v.getValue(i) * a);
    }
    return v2;
}

int main() {
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    cout << (a == b) << endl;
    cout << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for(unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;
    return 0;
}
