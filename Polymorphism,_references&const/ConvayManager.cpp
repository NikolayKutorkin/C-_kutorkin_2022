//
// Created by Николай on 04.03.2022.
//
class Car
{
public:
    // Разрешена ли посадка пассажиров
    bool isBoardingAllowed() const;

    // Разрешена ли погрузка грузов
    bool isLoadingAllowed() const;

    // Сколько в машине мест для пассажиров
    unsigned int getNumberOfSeats() const;

    // Сколько в машине мест для грузовых контейнеров
    unsigned int getNumberOfContainers() const;
};

class ConvoyManager
{
public:
    // Зарегистрировать новую машину в колонне
    void registerCar(const Car& c) {
        if(c.isBoardingAllowed()) {
            TotalSeats += c.getNumberOfSeats();
        }
        if(c.isLoadingAllowed()) {
            TotalContainers += c.getNumberOfContainers();
        }
    }

    // Сообщить, сколько всего пассажиров может принять колонна
    unsigned int getTotalSeats() const {
        return TotalSeats;
    }

    // Сообщить, сколько всего грузовых контейнеров может взять колонна
    unsigned int getTotalContainers() const {
        return TotalContainers;
    }

private:
    unsigned TotalSeats = 0;
    unsigned TotalContainers = 0;
};
