#include "supercar.h"

Supercar::Supercar(
    size_t id,
    std::string name,
    std::string model,
    size_t year,
    size_t maxSpeed
): Car(id, name, model, year), maxSpeed(maxSpeed) {}

Supercar::Supercar(const Supercar &other):
Car(other.id, other.name, other.model, other.year),
maxSpeed(other.maxSpeed) {}

CarType Supercar::GetType() const {
    return CarType::Supercar;
}

size_t Supercar::GetMaxSpeed() const {
    return maxSpeed;
}


std::shared_ptr<Car> Supercar::MakeShared() const {
    return std::make_shared<Supercar>(id, name, model, year, maxSpeed);
}

std::string Supercar::ToStr() const {
    std::stringstream ss;
    ss << Car::ToStr();
    ss << "\nMax speed: " << maxSpeed;
    return ss.str();
}

std::string Supercar::ToCSVStr() const {
    std::stringstream ss;
    std::string carstr = Car::ToCSVStr();
    ss << carstr.substr(0, carstr.length() - 2);
    ss << ",," << maxSpeed;
    return ss.str();
}
