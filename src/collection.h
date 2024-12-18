#pragma once
#include "car.h"
#include "vintage_car.h"
#include "supercar.h"
#include <unordered_set>

class CarCollection {
public:
    CarCollection();
    CarCollection(std::string filename);

    bool Add(const Car &car);
    bool Remove(const Car &car);
    bool Has(const Car& car) const;

    void operator<<(const Car& car);

    size_t Size();

    CarCollection WithType(CarType type) const;
    CarCollection OlderThen(size_t year) const;
    CarCollection NewerThen(size_t year) const;
private:
    std::unordered_set<Car> cars;
};
