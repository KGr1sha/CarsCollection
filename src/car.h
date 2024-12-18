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
    Car(std::string name, std::string model, size_t year);

    std::string GetName() const;
    std::string GetModel() const;
    size_t GetYear() const;
    virtual CarType GetType() const;

    bool SetName(std::string newName);
    void SetMode(std::string newModel);
    void SetYear(size_t newYear);

    virtual std::string ToStr() const;

    bool operator==(Car const &other) const;

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
