//
// Created by Николай on 22.04.2022.
//
#include <iostream>
#include <map>

struct Data {
    unsigned values_count = 0;
    long min_value = 0;
    long max_value = 0;
};

class TelemetryController {
public:
    // Получить и обработать событие. Параметрами передаются:
    // - device - идентификатор устройства, с которого пришло значение;
    // - value - собственно значение некоторой величины, переданное устройством.
    void handleEvent(const std::string &device, long value) {
        if (devices[device].values_count == 0) {
            devices[device].max_value = devices[device].min_value = value;
        }
        devices[device].values_count++;
        if (value > devices[device].max_value) devices[device].max_value = value;
        if (value < devices[device].min_value) devices[device].min_value = value;
    }

    // По идентификатору устройства возвращает,
    // сколько всего значений от него пришло за всё время
    unsigned int getEventsCount(const std::string &device) const {
        return devices.at(device).values_count;
    }

    // По идентификатору устройства возвращает
    // минимальное значение за всё время, пришедшее от данного устройства
    long getMinValue(const std::string &device) const {
        return devices.at(device).min_value;
    }

    // По идентификатору устройства возвращает
    // максимальное значение за всё время, пришедшее от данного устройства
    long getMaxValue(const std::string &device) const {
        return devices.at(device).max_value;
    }

private:
    std::map<std::string, Data> devices;
};
