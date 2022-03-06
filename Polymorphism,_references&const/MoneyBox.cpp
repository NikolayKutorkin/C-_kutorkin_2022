//
// Created by Николай on 04.03.2022.
//
#include <iostream>

class MoneyBox {
public:
    // Конструктор и деструктор, если нужны
    //MoneyBox() = default;
    // Добавить монетку достоинством value
    void addCoin(unsigned int value) {
        coin.first++;
        coin.second += value;
    }

    // Получить текущее количество монеток в копилке
    unsigned int getCoinsNumber() const {
        return coin.first;
    }

    // Получить текущее общее достоинство всех монеток
    unsigned int getCoinsValue() const {
        return coin.second;
    }

private:
    std::pair<unsigned, unsigned> coin;
};

int main() {
    MoneyBox m;
// Добавили монетку достоинством 10
    m.addCoin(10);
// Добавили монетку достоинством 5
    m.addCoin(5);

// Ожидаем, что монеток внутри 2 штуки
    std::cout << m.getCoinsNumber() << std::endl;
// Ожидаем, что общее достоинство всех монеток 15
    std::cout << m.getCoinsValue() << std::endl;

}
