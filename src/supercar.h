#pragma once
#include "car.h"

class Supercar : public Car {
public:
    Supercar(std::string name, std::string model, size_t year, size_t maxSpeed);

    CarType GetType() const final override;

    size_t GetMaxSpeed() const;

    std::string ToStr() const override;
private:
    size_t maxSpeed;
};
