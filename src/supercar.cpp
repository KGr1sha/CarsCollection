#include "car.cpp"
#include <sstream>

class Supercar : public Car {
public:
    Supercar(std::string name, std::string model, size_t year, size_t maxSpeed)
    : Car(name, model, year), maxSpeed(maxSpeed) {
        type = CarType::Supercar;
    }

    CarType GetType() const final override {
        return CarType::Supercar;
    }

    size_t GetMaxSpeed() const {
        return maxSpeed;
    }

    std::string ToStr() const override {
        std::stringstream ss;
        ss << Car::ToStr();
        ss << "\nMax speed: " << maxSpeed;
        return ss.str();
    }
private:
    size_t maxSpeed;
};
