#include "car.cpp"
#include <unordered_set>

class CarCollection {
public:
    bool AddCar(const Car &car) {
        return cars.insert(car).second;
    }
    bool RemoveCar(const Car &car) {
        return cars.erase(car);
    }
    bool HasCar(const Car& car) const {
        return cars.find(car) != cars.end();
    }

    void operator<<(const Car& car) {
        AddCar(car);
    }

    size_t GetNumberOfCars() {
        return cars.size();
    }

private:
    std::unordered_set<Car> cars;
};
