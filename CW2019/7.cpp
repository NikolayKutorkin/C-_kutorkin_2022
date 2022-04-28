//
// Created by Николай on 28.04.2022.
//
#include <iostream>
#include <set>
#include <algorithm>
int main() {
    auto cmp = [](const std::string& lhs, const std::string& rhs){
        return lhs.size() > rhs.size();
    };
    std::set<std::string, decltype(cmp)> words(cmp);
    int num_of_words = 0;
    std::cin >> num_of_words;
    for (auto i = 0; i < num_of_words; i++) {
        std::string word;
        std::cin >> word;
        words.insert(word);
    }

    for (auto& item: words) {
        std::cout << item << std::endl;
    }
    return 0;
}