#pragma once
#include <sstream>
#include <string>

enum CarType {
    Regular,
    Vintage,
    Supercar
};


class Car {
public:
    Car(std::string name, std::string model, size_t year)
    : name(name), model(model), year(year) {}

    std::string GetName() const {
        return name;
    }
    std::string GetModel() const {
        return model;
    }
    size_t GetYear() const {
        return year;
    }
    virtual CarType GetType() const {
        return CarType::Regular; 
    }

    bool SetName(std::string newName) {
        if (newName == "") {
            return false;
        }
        name = newName;
        return true;
    }
    void SetMode(std::string newModel) {
        model = newModel; 
    }
    void SetYear(size_t newYear) {
        year = newYear; 
    }

    virtual std::string ToStr() const {
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

protected:
    std::string name;        
    std::string model;
    size_t year;
    CarType type;
};

template<>
struct std::hash<Car> {
    size_t operator()(Car const &car) const {
        size_t h1 = std::hash<std::string>{}(car.GetName());
        size_t h2 = std::hash<std::string>{}(car.GetModel());
        return h1 ^ (h2 << 1);
    }
};

bool operator==(Car const &car1, Car const &car2) {
    return car1.GetName() == car2.GetName() && car1.GetModel() == car2.GetModel();
}
