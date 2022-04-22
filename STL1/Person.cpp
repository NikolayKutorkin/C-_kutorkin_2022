//
// Created by Николай on 17.04.2022.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
protected:
    string surname;
    string name;
    string middleName;
public:
    // Создать человека с ФИО

    Person(string _surname, string _name, string _middleName) : surname(_surname), name(_name),
                                                                middleName(_middleName) {}
    Person()= default;

    friend std::istream &operator>>(std::istream &is, Person& p);

    friend std::ostream &operator<<(std::ostream &os, const Person& p);

    bool operator< (const Person& p) {
        if (this->surname == p.surname) {
            if (this->name == p.name){
                if (this->middleName == p.middleName) return false;
                else return this->middleName < p.middleName;
            } else return this->name < p.name;
        } else return this->surname < p.surname;
    }
};

std::istream &operator>>(std::istream &is, Person& p) {
    is >> p.surname; //>> p.name >> p.middleName;
    is >> p.name;
    is >> p.middleName;
    return  is;
}

std::ostream &operator<<(std::ostream &os, const Person& p) {
    os << p.surname << " " << p.name << " " << p.middleName;
    return os;
}

int main() {
    cout << "Testing I/O" << endl;
    Person p;
    cin >> p;
    cout << p << endl;

    cout << "Testing sorting" << endl;
    vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));

    sort(people.begin(), people.end());
    for(vector<Person>::const_iterator it = people.begin(); it < people.end(); it++) {
        cout << *it << endl;
    }
    return 0;
}