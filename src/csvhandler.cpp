#include "csvhandler.h"
#include "collection.h"
#include <sstream>

bool CSVHandler::WriteCollection(
    CarCollection const &collection,
    std::string filename
) {
    std::ofstream file(filename);
    if (false == file.is_open()) {
        return false;
    }
    file << "ID,Name,Model,Year,Type,Number of owners,Max speed\n";
    for (const auto &car : collection.Cars()) {
        file << CarToStr(*car) << std::endl;
    }
    file.close();
    return true;
}

CarCollection CSVHandler::ReadCollection(
    std::string filename
) {
    CarCollection collection;
    std::ifstream file(filename);
    if (false == file.is_open()) {
        return collection;
    }
    std::string line;
    getline(file, line);
    while(file) {
        getline(file, line);
        if (line.length() == 0) {
            break;
        }
        std::shared_ptr<Car> sp = ParseCar(line);
        collection << *sp;
    }
    file.close();
    return collection;
}

std::shared_ptr<Car> CSVHandler::ParseCar(std::string str) {
    std::vector<std::string> parsed = Split(str, ","); 
    size_t id = stoi(parsed[0]);
    std::string name = parsed[1];
    std::string model = parsed[2];
    size_t year = std::stoi(parsed[3]);
    std::string typestr = parsed[4];
    if (typestr == "Regular") {
        return std::make_shared<Car>(id, name, model, year);
    } else if (typestr == "Vintage") {
        size_t noo = stoi(parsed[5]);
        return std::make_shared<VintageCar>(id, name, model, year, noo);
    } else { //Supercar
        size_t ms = stoi(parsed[6]);
        return std::make_shared<class Supercar>(id, name, model, year, ms);
    }
}

std::vector<std::string> CSVHandler::Split(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    std::string s(str);
    size_t pos = 0;
    std::string token;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        tokens.push_back(token);
        s = s.substr(pos + 1, s.length() - pos);
    }
    tokens.push_back(s);

    return tokens;
}

std::string CSVHandler::CarToStr(Car const &car) {
    std::stringstream ss; 
    ss << car.ToCSVStr();
    return ss.str();
}
