#pragma once
#include "collection.h"
#include <fstream>

class CSVHandler {
    static bool WriteCollection(
        CarCollection const &collection,
        std::string filename
    );
    static CarCollection ReadCollection(
        std::string filename
    );
};
