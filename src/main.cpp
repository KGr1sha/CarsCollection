#include <iostream>
#include "collection.h"
#include "vintage_car.h"

int main () {
    CarCollection collection;
    Car car1("model", "name", 1444);
    VintageCar car2("model2", "name2", 1555, 3);
    std::cout << car1.ToStr() << std::endl;
    std::cout << car2.ToStr() << std::endl;
    collection << car1;
    collection << car2;
    collection.Remove(car1);
    std::cout << collection.Size() << std::endl;
}
