#include "collection.h"
#include <memory>
#include <sstream>
#include <unordered_set>
#include <utility>

CarCollection::CarCollection() {}

CarCollection::CarCollection(const CarCollection &other) {
    cars = std::unordered_map<size_t, std::shared_ptr<Car>>(other.cars);
}

bool CarCollection::Add(const Car &car) {
    return cars.insert(
        std::make_pair(car.GetId(), car.MakeShared())
    ).second;
}

bool CarCollection::Remove(const Car &car) {
    return cars.erase(car.GetId());
}

bool CarCollection::Has(const Car& car) const {
    return cars.find(car.GetId()) != cars.end();
}

void CarCollection::operator<<(const Car& car) {
    Add(car);
}

size_t CarCollection::Size() {
    return cars.size();
}

std::unordered_set<std::shared_ptr<Car>> CarCollection::Cars() const {
    std::unordered_set<std::shared_ptr<Car>> set;
    for (const auto &pair : cars) {
        set.insert(pair.second);
    }
    return set;
}

CarCollection CarCollection::WithType(CarType type) const {
    CarCollection newCollection;
    for (const auto &pair : cars) {
        auto car = pair.second;
        if (car->GetType() == type) {
            newCollection << *car;
        }
    }
    return newCollection;
}

CarCollection CarCollection::OlderThen(size_t year) const {
    CarCollection newCollection;
    for (const auto &pair : cars) {
        auto car = pair.second;
        if (car->GetYear() <= year) {
            newCollection << *car;
        }
    }
    return newCollection;
}

CarCollection CarCollection::NewerThen(size_t year) const {
    CarCollection newCollection;
    for (const auto &pair : cars) {
        auto car = pair.second;
        if (car->GetYear() >= year) {
            newCollection << *car;
        }
    }
    return newCollection;
}

std::string CarCollection::ToStr() const {
    std::stringstream ss;
    ss << "___COLLECTION___\n"; 
    for (const auto &pair : cars) {
        ss << pair.second->ToStr() << "\n";
    }
    return ss.str(); 
}
