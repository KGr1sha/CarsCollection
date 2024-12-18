#include <iostream>
#include "collection.cpp"
#include "vintage_car.cpp"

using namespace std;

int main () {
    CarCollection col;
    VintageCar car1("abc", "bca", 1, 0);
    cout << car1.ToStr() << endl;
    col << car1;
}
