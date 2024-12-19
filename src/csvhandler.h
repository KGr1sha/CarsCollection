#pragma once
#include "collection.h"
#include <fstream>
#include <memory>
#include <vector>

class CSVHandler {
public:
    static bool WriteCollection(
        CarCollection const &collection,
        std::string filename
    );

    static CarCollection ReadCollection(
        std::string filename
    );

private:
    static std::string CarToStr(const Car &car);
    static std::shared_ptr<Car> ParseCar(const std::string);
    static std::vector<std::string> Split(const std::string &str, const std::string &delimeter);
};