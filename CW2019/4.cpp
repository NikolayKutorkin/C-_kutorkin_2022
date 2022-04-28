//
// Created by Николай on 28.04.2022.
//
// Абстрактное транспортное средство
class Vehicle {
public:
    // Может ли ездить по суще
    virtual bool canDrive() const {
        return false;
    }

    // Может ли плавать
    virtual bool canSail() const {
        return false;
    }

    // Может ли летать
    virtual bool canFly() const {
        return false;
    }

    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
    bool canDrive() const override {
        return true;
    }
};

class Ship : public Vehicle {
    bool canSail() const override {
        return true;
    }
};

class Plane : public Vehicle {
    bool canFly() const override {
        return true;
    }
};

class Truck : public Car {

};