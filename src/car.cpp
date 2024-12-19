#include <iostream>
#include <memory>
#include "car.h"

Car::Car(size_t id, std::string name, std::string model, size_t year):
id(id), name(name), model(model), year(year) {}

Car::Car(const Car &other):
Car(other.id, other.name, other.model, other.year) {}

size_t Car::GetId() const {
    return id;
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

void Car::SetId(size_t newId) {
    id = newId;
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

std::shared_ptr<Car> Car::MakeShared() const {
    return std::make_shared<Car>(id, name, model, year);
}

bool Car::operator==(const Car &other) const {
    return id == other.id && name == other.GetName() && model == other.GetModel();
}

std::string Car::ToStr() const {
    std::stringstream ss;
    ss << "--CAR--\n";
    ss << "id: " << id << "\nName: " << name << "\nModel: " << model << "\nYear: " << year;
    switch(GetType()) {
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

std::string Car::ToCSVStr() const {
    std::stringstream ss; 
    ss << id << "," 
    << name << ","
    << model << ","
    << year << ",";
    switch(GetType()) {
        case CarType::Regular:
            ss << "Regular";
            break;
        case CarType::Vintage:
            ss << "Vintage";
            break;
        case CarType::Supercar:
            ss << "Supercar";
            break;
    }
    ss << ",,";
    return ss.str();
}
