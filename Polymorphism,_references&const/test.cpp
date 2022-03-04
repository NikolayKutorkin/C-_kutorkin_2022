//
// Created by Николай on 25.02.2022.
//
#include <iostream>
using namespace std;
struct point {
    double x, y;
};
int main() {
    point p;
    point& pi;
    pi = p;
    cout << pi.x << endl;

}
