#pragma once
#include "car.h"
#include <memory>

class VintageCar : public Car {
public:
    VintageCar(
        size_t id,
        std::string name, std::string model,
        size_t year,
        size_t numberOfOwners
    );
    VintageCar(const VintageCar &other);

    CarType GetType() const final override;

    size_t GetNumberOfOwners() const;

    std::string ToStr() const override;
    std::string ToCSVStr() const override;

    std::shared_ptr<Car> MakeShared() const final override;
private:
    size_t numberOfOwners;
};