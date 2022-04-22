//
// Created by Николай on 17.04.2022.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class ResultsTable
{
protected:
    vector<unsigned> scores;
public:
    // Зарегистрировать новый результат,
    // нас волнуют только баллы, имена пользователей не важны
    void addResult(unsigned int score) {
        scores.push_back(score);
        sort(scores.begin(), scores.end());
    }

    // Получить минимальный балл из всех результатов за всё время
    unsigned int getMinScore() const {

        return *min_element(scores.begin(), scores.end());
    }

    // Получить, сколько баллов у игрока на заданном месте.
    // Внимание: места нумеруются так, как это принято на турнирах, то есть
    // лучший результат - 1-ое место, за ним 2-ое место и т.д.
    unsigned int getScoreForPosition(unsigned int positionNumber) const {
        return scores[scores.size()  - positionNumber];
    }
};

int main() {
    ResultsTable t;

    t.addResult(30);
    t.addResult(85);
    t.addResult(12);
    t.addResult(31);

    cout << "1st place score: " << t.getScoreForPosition(1) << endl;
    cout << "2nd place score: " << t.getScoreForPosition(2) << endl;
    cout << "3rd place score: " << t.getScoreForPosition(3) << endl;
    cout << "Min score during the tournament: " << t.getMinScore() << endl;
    return 0;
}
