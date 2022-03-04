//
// Created by Николай on 04.03.2022.
//
// Класс предмета
#include <iostream>
using std::string;

class Item {
protected:
    string title;
    int weight;
    int level;
    bool magical;

public:
    // Так можно создать предмет, указав его название, вес, уровень и магичность
    Item(string title, int weight, int level, bool magical) {
        this->title = title;
        this->weight = weight;
        this->level = level;
        this->magical = magical;
    }

    // Получить вес предмета
    int getWeight() const {
        return weight;
    }

    // Получить уровень предмета
    int getLevel() const {
        return level;
    }

    // Получить, является ли предмет магичным
    int isMagical() const {
        return magical;
    }
};

// Базовый класс героя
class Player {
protected:
    // Сила и уровень героя
    int strength;
    int level;

public:
    // Создать героя, все подробности будут указаны позже
    Player() { }
    // Удалить героя, ничего умного эта процедура пока что не требует
    virtual ~Player() { }

    // Базовые методы, пока что очень простые.
    // На данном этапе можно считать, что для всех героев они ведут себя одинаково,
    // так что пусть будут в базовом классе.

    // Задать силу
    virtual void setStrength(int strength) final {
        this->strength = strength;
    }
    // Задать уровень
    virtual void setLevel(int level) final {
        this->level = level;
    }

    // Получить силу
    virtual int getStrength() const final {
        return strength;
    }
    // Получить уровень
    virtual int getLevel() const final {
        return level;
    }

    // Проверка, может ли игрок использовать предмет.
    // Рыцарь может использовать (а) только немагические предметы и только если
    // (б) сила героя не меньше веса предмета, (в) уровень героя не меньше уровня предмета.
    // Волшебник устроен в целом так же, но магические предметы использовать тоже может.
    //virtual bool canUse(const Item& item) const = 0;

    // Может ли игрок колдовать, зависит от конкретного класса игрока
    //virtual bool canCast() const = 0;

    // Проверка, может ли игрок лечить других игроков.
    // Лечить умеет или любой волшебник, или
    // игрок достаточно высокого уровня.

};

class Knight : public Player {
public:
    bool canUse(const Item& item) const {
        if (item.isMagical() == 1) {
            return false;
        } else if (item.getWeight() > strength) {
            return false;
        } else if (item.getLevel() > level) {
            return false;
        } else return true;
    }
    bool canCast() const {
        return false;
    }
    virtual bool canHeal() const {
        return canCast() || getLevel() > 10;
    }
};

class Wizard : public Player {
public:
    bool canUse(const Item& item) const {
        if (item.getWeight() > strength) {
            return false;
        } else if (item.getLevel() > level) {
            return false;
        } else return true;
    }
    bool canCast() const {
        return true;
    }
    virtual bool canHeal() const {
        return canCast() || getLevel() > 10;
    }
};
