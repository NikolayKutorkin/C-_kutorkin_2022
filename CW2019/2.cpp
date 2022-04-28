//
// Created by Николай on 28.04.2022.
//
#include <vector>
#include <cmath>

class Polyline {
protected:
    std::vector<std::pair<double, double>> points;
public:
    // Конструктур и деструктор, если необходимы

    // Добавить очередную точку в ломаную
    void addPoint(double x, double y) {
        std::pair<double, double> p(x, y);
        points.push_back(p);
    }

    // Получить количесто точек в ломаной в данный момент
    unsigned int getNumberOfPoints() const {
        return points.size();
    }

    // Получить длину ломаной в данный момент
    double getLength() const {
        double dist = 0;
        for (auto i = 1u; i < points.size(); i++) {
            dist += sqrt(pow((points[i - 1].first - points[i].first), 2) +
                         pow((points[i - 1].second - points[i].second), 2));
        }
        return dist;
    }

    // Получить x-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getX(unsigned int i) const {
        return points[i].first;
    }

    // Получить y-координату i-ой точки ломаной, точки нумеруются в порядке добавления
    // (Гарантируется, что номер i строго меньше, чем то, вернула ваша getNumberOfPoints())
    double getY(unsigned int i) const {
        return points[i].second;
    }
};
