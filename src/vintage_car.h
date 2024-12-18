#pragma once
#include "car.h"

class VintageCar : public Car {
public:
    VintageCar(std::string name, std::string model, size_t year, size_t numberOfOwners);

    CarType GetType() const final override;

    size_t GetNumberOfOwners() const;

    std::string ToStr() const override;
private:
    size_t numberOfOwners;
};
