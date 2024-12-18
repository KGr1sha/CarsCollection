#include "car.cpp"

class VintageCar : public Car {
public:
    VintageCar(std::string name, std::string model, size_t year, size_t numberOfOwners):
    Car(name, model, year), numberOfOwners(numberOfOwners) {
        type = CarType::Vintage;
    }

    CarType GetType() const final override {
        return CarType::Vintage;
    }

    size_t GetNumberOfOwners() const {
        return numberOfOwners;
    }

    std::string ToStr() const override {
        std::stringstream ss;
        ss << Car::ToStr();
        ss << "\nNumber of owners: " << numberOfOwners;
        return ss.str();
    }
private:
    size_t numberOfOwners;
};
