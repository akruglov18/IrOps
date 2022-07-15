#ifndef _UTILS_H_
#define _UTILS_H_

#include <unordered_map>
#include <string>

namespace Utils {

bool saveToFile(const std::unordered_map<std::string, int>& map, const std::string& name);

std::string getBuildDirPath();
}

#endif
