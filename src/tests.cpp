#include <iostream>
#include <assert.h>
#include "car.h"
#include "collection.h"
#include "supercar.h"
#include "vintage_car.h"

bool test(int test_id) {
    switch (test_id) {
        case 1: { //car class
            Car car1(1, "name", "model", 1995);
            assert(car1.GetId() == 1);
            assert(car1.GetName() == "name");
            assert(car1.GetModel() == "model");
            assert(car1.GetYear() == 1995);
            assert(car1.GetType() == CarType::Regular);
            Car car2(car1);
            car2.SetId(2);
            car2.SetName("name 2");
            assert(car2.GetId() == 2);
            assert(car2.GetName() == "name 2");
            break;
        }
        case 2: { //vintage car
            VintageCar vcar(1, "name", "model", 1990, 3);
            assert(vcar.GetType() == CarType::Vintage);
            assert(vcar.GetNumberOfOwners() == 3);
            break;
        }
        case 3: { //supercar
            class Supercar scar(1, "super name", "pooper model", 2020, 450);
            assert(scar.GetType() == CarType::Supercar);
            assert(scar.GetMaxSpeed() == 450);
            break;
        }
        case 4: { //collection
            break;
        }
        case 5: {
            break;
        }
        case 6: {
            break;
        }
    
        default:
            return false;
    }
    return true;
}

int main() {
    int testid = 0;
    while(test(++testid)) {
        std::cout << "Test " << testid << " passed" << std::endl;
    }
    std::cout << "All tests passed" << std::endl;
}
