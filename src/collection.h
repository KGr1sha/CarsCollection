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
private:
    std::unordered_set<Car> cars;
};
