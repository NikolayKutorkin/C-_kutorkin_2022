//
// Created by Николай on 16.04.2022.
//
#include <iostream>
class Student
{
public:
    // Задать имя студента
    void setName(std::string name){
        this->name = name;
    }

    // Указать количество баллов за контрольную
    void setScore(unsigned int score){
        this->score = score;
    }

    // Получить имя студента
    std::string getName() const {
        return name;
    }

    // Получить количество баллов студента
    unsigned int getScore() const {
        return score;
    }

private:
    std::string name;
    unsigned int score;
};

std::istream& operator>>(std::istream &is, Student& student) {
    std::string name_of_student;
    std::getline(is, name_of_student);
    student.setName(name_of_student);
    student.setScore(0);
    return is;
}

std::ostream& operator<<(std::ostream &os, Student& student) {
    os << "'" << student.getName() << "': " << student.getScore();
    return os;
}

int main() {
    Student s;
    std::cin >> s;
    s.setScore(10);
    std::cout << s << std::endl;
}