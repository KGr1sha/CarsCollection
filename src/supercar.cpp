#include "supercar.h"

Supercar::Supercar(std::string name, std::string model, size_t year, size_t maxSpeed)
: Car(name, model, year), maxSpeed(maxSpeed) {
    type = CarType::Supercar;
}

CarType Supercar::GetType() const {
    return CarType::Supercar;
}

size_t Supercar::GetMaxSpeed() const {
    return maxSpeed;
}

std::string Supercar::ToStr() const {
    std::stringstream ss;
    ss << Car::ToStr();
    ss << "\nMax speed: " << maxSpeed;
    return ss.str();
}
