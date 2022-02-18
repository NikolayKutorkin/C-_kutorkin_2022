//
// Created by Николай on 17.02.2022.
//
#include <iostream>

class Animal {
public:
    virtual std::string getType() = 0;
    virtual bool isDangerous() = 0;
};

class ZooKeeper {
public:
    // Создаём смотрителя зоопарка
    ZooKeeper() {}

    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal* a){
        if (a->isDangerous() == 1) count_dangerous++;
    }

    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount(){
        return count_dangerous;
    }

protected:
    int count_dangerous = 0;
};

int main() {
    std::cout << "Heel";
}

