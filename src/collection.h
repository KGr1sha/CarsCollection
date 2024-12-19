#pragma once
#include "vintage_car.h"
#include "supercar.h"
#include <memory>
#include <unordered_map>
#include <unordered_set>

class CarCollection {
public:
    CarCollection();
    CarCollection(const CarCollection &other);

    bool Add(const Car &car);
    bool Remove(const Car &car);
    bool Has(const Car& car) const;

    void operator<<(const Car& car);

    size_t Size();

    CarCollection WithType(CarType type) const;
    CarCollection OlderThen(size_t year) const;
    CarCollection NewerThen(size_t year) const;

    std::unordered_set<std::shared_ptr<Car>> Cars() const;

    std::string ToStr() const;
    
private:
    std::unordered_map<size_t, std::shared_ptr<Car>> cars;
};
