//
// Created by Николай on 18.02.2022.
//
#include <iostream>
class Storage
{
public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n) {
        data = new int[n];
        this->n = n;
    }

    // Добавьте нужный деструктор
    virtual ~Storage() {
        delete[] data;
    }

    // Получение размерности хранилища
    unsigned getSize() const{
        return n;
    }

    // Получение значения i-го элемента из хранилища,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    int getValue(unsigned int i) {
        if (i < n) return data[i];
    }

    // Задание значения i-го элемента из хранилища равным value,
    // i находится в диапазоне от 0 до n-1,
    // случаи некорректных i можно не обрабатывать.
    void setValue(unsigned int i, int value) {
        if (i < n) data[i] = value;
    }

private:
    int* data;
    unsigned n;
};
}