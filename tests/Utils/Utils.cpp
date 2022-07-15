#include "Utils.h"
#include <fstream>
#include <algorithm>
#include <iostream>

namespace Utils {

bool saveToFile(const std::unordered_map<std::string, int>& map, const std::string& name) {
    std::ofstream stream(name);
    if (!stream.is_open()) {
        return false;
    }
    for (auto row : map) {
        stream << row.first << " " << row.second;
    }
    return true;
}

std::string getBuildDirPath() {
    char* env = std::getenv("BUILD_DIR");
    if (env != nullptr) {
        auto str = std::string(env);
        std::cout << str << "\n";
        return str;
    }
    return std::string();
}

}
