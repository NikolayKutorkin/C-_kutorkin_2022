//
// Created by Николай on 22.04.2022.
//
#include <iostream>
#include <set>

class SessionManager {
public:
    // Вход пользователя.
    // Один пользователь может войти несколько раз подряд,
    // считать его при этом нужно один раз.
    void login(const std::string &username) {
        users.insert(username);
    }

    // Выход пользователя.
    // Пользователь может выйти несколько раз подряд,
    // падать при этом не нужно.
    void logout(const std::string &username) {
        users.erase(username);
    }

    // Сколько сейчас пользователей залогинено.
    int getNumberOfActiveUsers() const {
        return users.size();
    }

private:
    std::set<std::string> users;
};
