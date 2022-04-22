//
// Created by Николай on 17.04.2022.
//
#include <iostream>
#include <vector>

class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size) {
        this->cpuNum = cpuNum;
        this->size = size;
    }

    // На каком ядре процессора выполняется задача
    int getCPU() const {
        return cpuNum;
    }

    // Оценка сложности задачи (в попугаях)
    int getSize() const {
        return size;
    }
};

class Analyzer
{
protected:
    std::vector<int> sizes;
public:
    // Создать анализатор для системы с numCores ядер
    Analyzer(int numCores) {
        sizes.resize(numCores);
        for(int i = 0; i < numCores; i++) {
            sizes[i] = 0;
        }
    }

    // Проанализировать текущие задачи
    void analyze(const std::vector<Task>& tasks) {
        for(unsigned i = 0; i < tasks.size(); i++) {
            int number = tasks[i].getCPU();
            sizes[number] += tasks[i].getSize();
        }
    }

    // Сообщить общую нагрузку на заданное ядро
    int getLoadForCPU(int cpuNum) {
        return sizes[cpuNum];
    }
};

int main() {
    int numberOfCores = 4;
    std::vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
    Analyzer a(numberOfCores);
    a.analyze(data);
    for(int i = 0; i < numberOfCores; i++)
        std::cout << a.getLoadForCPU(i) << std::endl;
    return 0;
}
