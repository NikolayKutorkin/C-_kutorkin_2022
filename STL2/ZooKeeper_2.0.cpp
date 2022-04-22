//
// Created by Николай on 21.04.2022.
//
#include <iostream>
#include <map>
using namespace std;
class Animal {
public:
    virtual string getType() const = 0;
    virtual ~Animal() = default;
};

class ZooKeeper {
protected:
    map<string, int> animals;
public:
    // Создаём смотрителя зоопарка
    ZooKeeper() = default;

    // Смотрителя попросили обработать очередного зверя.
    void handleAnimal(const Animal& a) {
        animals[a.getType()]++;
    }

    // Возвращает, сколько зверей такого типа было обработано.
    // Если таких не было, возвращает 0.
    int getAnimalCount(const string& type) const {
        return animals[type];
    }
};
