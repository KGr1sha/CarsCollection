#include <iostream>
#include "car.h"

Car::Car(std::string name, std::string model, size_t year)
: name(name), model(model), year(year) {
    type = CarType::Regular;
}

std::string Car::GetName() const {
    return name;
}
std::string Car::GetModel() const {
    return model;
}
size_t Car::GetYear() const {
    return year;
}
CarType Car::GetType() const {
    return CarType::Regular; 
}

bool Car::SetName(std::string newName) {
    if (newName == "") {
        return false;
    }
    name = newName;
    return true;
}
void Car::SetMode(std::string newModel) {
    model = newModel; 
}
void Car::SetYear(size_t newYear) {
    year = newYear; 
}

std::string Car::ToStr() const {
    std::stringstream ss;
    ss << "--CAR--\n";
    ss << "Name: " << name << "\nModel: " << model << "\nYear: " << year;
    switch(type) {
        case CarType::Regular:
            ss << "\nType: Regular";
            break;
        case CarType::Vintage:
            ss << "\nType: Vintage";
            break;

        case CarType::Supercar:
            ss << "\nType: Supercar";
            break;
    }
    return ss.str();
}

bool Car::operator==(Car const &other) const {
    return name == other.GetName() && model == other.GetModel();
}
