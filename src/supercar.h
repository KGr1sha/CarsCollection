#pragma once
#include "car.h"

class Supercar : public Car {
public:
    Supercar(
        size_t id,
        std::string name,
        std::string model,
        size_t year,
        size_t maxSpeed
    );
    Supercar(const Supercar &other);

    CarType GetType() const final override;

    size_t GetMaxSpeed() const;

    std::shared_ptr<Car> MakeShared() const final override;

    std::string ToStr() const override;
    std::string ToCSVStr() const override;
private:
    size_t maxSpeed;
};
