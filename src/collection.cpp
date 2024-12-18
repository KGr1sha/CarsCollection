#include "collection.h"

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
