#include "vintage_car.h"
#include "car.h"
#include <memory>
#include <sstream>

VintageCar::VintageCar(size_t id, std::string name, std::string model, size_t year, size_t numberOfOwners):
Car(id, name, model, year), numberOfOwners(numberOfOwners) {}

VintageCar::VintageCar(const VintageCar &other):
Car(other.id, other.name, other.model, other.year),
numberOfOwners(other.numberOfOwners) {}

CarType VintageCar::GetType() const {
    return CarType::Vintage;
}

size_t VintageCar::GetNumberOfOwners() const {
    return numberOfOwners;
}

std::shared_ptr<Car> VintageCar::MakeShared() const {
    return std::make_shared<VintageCar>(id, name, model, year, numberOfOwners);
}

std::string VintageCar::ToStr() const {
    std::stringstream ss;
    ss << Car::ToStr();
    ss << "\nNumber of owners: " << numberOfOwners;
    return ss.str();
}

std::string VintageCar::ToCSVStr() const {
    std::stringstream ss;
    std::string carstr = Car::ToCSVStr();
    ss << carstr.substr(0, carstr.length() - 2);
    ss << "," << numberOfOwners << ",";
    return ss.str();
}
