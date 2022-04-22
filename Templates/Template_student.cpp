//
// Created by Николай on 16.04.2022.
//
#include <iostream>
struct student {
    std::string name;
    std::string id_number_string;
};

bool operator== (const student& a, const student& b) {
    return a.id_number_string == b.id_number_string;
}

int main() {
    student a = {"Andy", "1234 123123"};
    student b = {"Andrew", "1234 123123"};
    student c = {"Andy", "1234123123"};
    std::cout << (a == b) << " " << (a == c) << " " << (b == c);
    std::cout << (b == a) << " " << (c == a) << " " << (c == b);
}
