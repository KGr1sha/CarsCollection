#include "collection.h"
#include <unordered_set>

CarCollection::CarCollection() {}

CarCollection::CarCollection(std::string filename) {}

bool CarCollection::Add(const Car &car) {
    return cars.insert(car).second;
}
bool CarCollection::Remove(const Car &car) {
    return cars.erase(car);
}
bool CarCollection::Has(const Car& car) const {
    return cars.find(car) != cars.end();
}
void CarCollection::operator<<(const Car& car) {
    Add(car);
}
size_t CarCollection::Size() {
    return cars.size();
}

CarCollection CarCollection::WithType(CarType type) const {
    CarCollection newCollection;
    for (const Car &car : cars) {
        if (car.GetType() == type) {
            newCollection << car;
        }
    }
    return newCollection;
}

CarCollection CarCollection::OlderThen(size_t year) const {
    CarCollection newCollection;
    for (const Car &car : cars) {
        if (car.GetYear() >= year) {
            newCollection << car;
        }
    }
    return newCollection;
}

CarCollection CarCollection::NewerThen(size_t year) const {
    CarCollection newCollection;
    for (const Car &car : cars) {
        if (car.GetYear() <= year) {
            newCollection << car;
        }
    }
    return newCollection;
}
