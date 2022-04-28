//
// Created by Николай on 28.04.2022.
//
#include <iostream>
#include <set>
using namespace std;

class Module {
public:
    // Получить имя модуля
    virtual string getName() const = 0;

    // Запустить модуль
    virtual void run() = 0;
};

class ModuleA : public Module {
public:
    string getName() const {
        return "moduleA";
    }

    void run() {
        cout << "ModuleA runs" << endl;
    }
};

class ModuleB : public Module {
public:
    string getName() const {
        return "moduleB";
    }

    void run() {
        cout << "ModuleB runs" << endl;
    }
};

class Dispatcher {
protected:
    std::set<Module*> modules;
public:
    // Зарегистрировать переданный модуль
    void registerModule(Module* m) {
        for (auto module : modules){
            if (module->getName() == m->getName()) return;
        }
        modules.insert(m);
    }

    // Вызвать метод run для модуля с именем moduleName
    // Если такого модуля не зарегистрировано, ничего не делать (но не падать)
    void runModule(const string& moduleName) const {
        for (auto module : modules){
            if (module->getName() == moduleName) module->run();
        }
    }
};
