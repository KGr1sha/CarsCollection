#pragma once
#include <memory>
#include <sstream>
#include <string>

enum CarType {
    Regular,
    Vintage,
    Supercar
};

class Car {
public:
    Car(size_t id, std::string name, std::string model, size_t year);
    Car(const Car &other);

    size_t GetId() const;
    std::string GetName() const;
    std::string GetModel() const;
    size_t GetYear() const;
    virtual CarType GetType() const;

    bool SetName(std::string newName);
    void SetMode(std::string newModel);
    void SetYear(size_t newYear);
    void SetId(size_t newId);

    virtual std::string ToStr() const;
    virtual std::string ToCSVStr() const;

    bool operator==(Car const &other) const;

    virtual std::shared_ptr<Car> MakeShared() const;

protected:
    size_t id;
    std::string name;        
    std::string model;
    size_t year;
};

template<>
struct std::hash<Car> {
    size_t operator()(const Car &car) const {
        return std::hash<size_t>{}(car.GetId());
    }
};