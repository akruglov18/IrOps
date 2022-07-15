#include "Utils.h"
#include <fstream>

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
        return std::string(env) + "/build/";
    }
    return std::string("C:/Users/skytt/Desktop/OV/IrOps/build/");
}

}
