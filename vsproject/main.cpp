#include <fstream>
#include <stdio.h>
#include <iostream>
#include <assert.h>
#include "../src/csvhandler.h"


bool exists(const std::string& filename) {
    std::ifstream f(filename);
    return f.good();
}

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
        CarCollection collection;
        Car car1(1, "n", "m", 1000);
        VintageCar car2(2, "n", "m", 2000, 3);
        class Supercar car3(3, "n", "m", 3000, 500);
        collection.Add(car1);
        collection << car2;
        collection << car3;
        assert(collection.Size() == 3);
        collection.Remove(car3);
        assert(collection.Size() == 2);
        collection << car3;
        assert(collection.WithType(Regular).Size() == 1);
        assert(collection.WithType(Vintage).Size() == 1);
        assert(collection.WithType(Supercar).Size() == 1);
        assert(collection.OlderThen(1500).Size() == 1);
        assert(collection.NewerThen(2000).Size() == 2);
        assert(
            collection
            .NewerThen(2000)
            .WithType(Supercar)
            .Size() == 1
        );
        break;
    }
    case 5: { //csv file writing & reading
        CarCollection collection;
        Car car1(1, "n", "m", 1000);
        VintageCar car2(2, "n", "m", 2000, 3);
        class Supercar car3(3, "n", "m", 3000, 500);
        collection << car1;
        collection << car2;
        collection << car3;

        CSVHandler::WriteCollection(collection, "test.csv");
        CarCollection col2 = CSVHandler::ReadCollection("test.csv");
        assert(col2.Size() == 3);
        assert(col2.Has(car1));
        assert(col2.Has(car2));
        assert(col2.Has(car3));
        assert(col2.WithType(Regular).Size() == 1);
        assert(col2.WithType(Vintage).Size() == 1);
        assert(col2.WithType(Supercar).Size() == 1);

        if (exists("test.csv")) {
            remove("test.csv");
        }
        break;
    }

    default:
        return false;
    }
    return true;
}

int main() {
    int testid = 0;
    while (test(++testid)) {
        std::cout << "Test " << testid << " passed" << std::endl;
    }
    std::cout << "All tests passed" << std::endl;


    CarCollection collection;
    Car car1(1, "n", "m", 1000);
    VintageCar car2(2, "n", "m", 2000, 3);
    class Supercar car3(3, "n", "m", 3000, 500);
    collection << car1;
    collection << car2;
    collection << car3;
    CSVHandler::WriteCollection(collection, "out.csv");
}