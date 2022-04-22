//
// Created by Николай on 11.03.2022.
//
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
#include <random>

int main() {
    // 1
    std::vector<int> P1(10);
    std::iota(P1.begin(), P1.end(), 1);

    for (auto& item: P1) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    // 2
    int N = 0;
    std::cin >> N;
    for(int a, i = 0; i < N; i++) {
        std::cin >> a;
        P1.push_back(a);
    }
    for (auto& item: P1) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    // 3
    std::default_random_engine generator(0);
    std::shuffle(std::begin(P1), std::end(P1), generator);

    for (auto& item: P1) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    // 4
    std::sort(P1.begin(), P1.end());
    auto to_delete = std::unique(P1.begin(), P1.end());
    P1.erase(to_delete, P1.end());

    for (auto& item: P1) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    // 5
    auto odd = std::count_if(P1.begin(), P1.end(), [](auto number){return number % 2 != 0;});
    std::cout << "How many odd numbers: " << odd << std::endl;

    //6
    auto minmax = std::minmax_element(P1.begin(), P1.end());
    std::cout << "Max: " << *minmax.second << ", Min: " << *minmax.first << std::endl;

    // 7
    auto prime = std::find_if(P1.begin(), P1.end(), [](auto number){
        if (number == 1 || number == 0) return false;
        if (number == 2) return true;
        else {
            for (auto i = 2; i <= number / 2; i++) {
                if (number % i == 0) return false;
            }
        }
        return true;
    });
    std::cout << "Prime number: " << *prime << std::endl;

    // 8
    std::transform(P1.begin(), P1.end(), P1.begin(), [](auto elem){return elem * elem;});
    for (auto& item: P1) {
        std::cout << item << ' ';
    }
    std::cout << std::endl;

    // 9
    std::vector<int> P2(P1.size());

}
