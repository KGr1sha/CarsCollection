#include <iostream>
#include "collection.h"
#include "csvhandler.h"

int main () {
    CarCollection collection;
    Car car1(1, "name", "model", 1444);
    VintageCar car2(2, "vname", "vmodel", 1995, 3);
    class Supercar car3(3, "supername", "bomba", 2020, 400);
    collection << car1;
    collection << car2;
    collection << car3;
    //CSVHandler::WriteCollection(collection, "out.csv");
    CarCollection col2 = CSVHandler::ReadCollection("out.csv");
    std::cout << col2.ToStr() << std::endl;
}
