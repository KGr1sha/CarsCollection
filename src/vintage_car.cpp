#include "vintage_car.h"

VintageCar::VintageCar(std::string name, std::string model, size_t year, size_t numberOfOwners):
Car(name, model, year), numberOfOwners(numberOfOwners) {
    type = CarType::Vintage;
}

CarType VintageCar::GetType() const {
    return CarType::Vintage;
}

size_t VintageCar::GetNumberOfOwners() const {
    return numberOfOwners;
}

std::string VintageCar::ToStr() const {
    std::stringstream ss;
    ss << Car::ToStr();
    ss << "\nNumber of owners: " << numberOfOwners;
    return ss.str();
}
