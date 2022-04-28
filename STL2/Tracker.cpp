//
// Created by Николай on 22.04.2022.
//
#include <iostream>
#include <map>

struct Data {
    unsigned long long values_count = 0;
    unsigned long long min_value = 0;
    unsigned long long max_value = 0;
};
class Tracker
{
public:
    // При любом действии пользователя вызывается этот метод.
    // Методу передаётся:
    // - какой пользователь совершил действие (username);
    // - когда (timestamp - для простоты условные секунды от начала времён).
    // Внимание: не гарантируется, что timestamp расположены строго по
    // возрастанию, в них может быть любой бардак.
    void click(const std::string& username, unsigned long long timestamp) {
        if (users[username].values_count == 0) {
            users[username].max_value = users[username].min_value = timestamp;
        }
        users[username].values_count++;
        if (timestamp > users[username].max_value) users[username].max_value = timestamp;
        if (timestamp < users[username].min_value) users[username].min_value = timestamp;
    }

    // По имени пользователя нужно вернуть, сколько всего было кликов
    unsigned long long getClickCount(const std::string& username) const{
        return users.at(username).values_count;
    }

    // Когда был первый клик
    unsigned long long getFirstClick(const std::string& username) const {
        return users.at(username).min_value;
    }

    // Когда был последний клик
    unsigned long long getLastClick(const std::string& username) const {
        return users.at(username).max_value;
    }

private:
    std::map<std::string, Data> users;
};
