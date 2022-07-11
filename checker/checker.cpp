#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

bool fillMap(std::ifstream& stream, std::map<std::string, int>& map, const std::string &error) {
    while (!stream.eof()) {
        std::string name;
        int value;
        stream >> name >> value;
        if (map.find(name) != map.end()) {
            std::cout << error << '\n';
            std::cout << "Name: " << name << '\n';
            return false;
        }
        map[name] = value;
    }
    return true;
}

int main(int argc, char** argv) {
    if (argc < 3) {
        std::cout << "No provided args";
        return 0;
    }
    std::string path_ref(argv[1]);
    std::string path_new(argv[2]);
    std::cout << "path_ref: " << path_ref << '\n' << "path_new " << path_new << '\n';
    std::map<std::string, int> values_ref;
    std::ifstream ref_file(path_ref);
    if (!ref_file.is_open()) {
        std::cout << "Can't open file: " << path_ref << "\n";
        return 0; 
    }
    if (!fillMap(ref_file, values_ref, "Repeated value in reference")) {
        return 0;
    }
    std::map<std::string, int> values_new;
    std::ifstream new_file(path_new);
    if (!new_file.is_open()) {
        std::cout << "Can't open file: " << path_new << "\n";
        return 0; 
    }
    if (!fillMap(new_file, values_new, "Repeated value in new")) {
        return 0;
    }
    std::vector<std::string> new_tests;
    std::vector<std::string> deleted_tests;
    std::vector<std::string> changed_tests;
    for (auto new_value : values_new) {
        auto it = values_ref.find(new_value.first);
        if (it == values_ref.end()) {
            new_tests.push_back(new_value.first);
        } else {
            double diff = static_cast<double>(it->second - new_value.second) / it->second;
            if (diff >= 0) {
                changed_tests.push_back(new_value.first + " improves on: " + std::to_string(diff * 100) + "%");
            } else {
                changed_tests.push_back(new_value.first + " slowing down on: " + std::to_string(-diff * 100) + "%");
            }
            values_ref.erase(it);
        }
    }
    for (const auto& value : values_ref) {
        deleted_tests.push_back(value.first);
    }
    for (const auto& str : deleted_tests) {
        std::cout << "Deleted: " << str << '\n';
    }
    for (const auto& str : new_tests) {
        std::cout << "Added: " << str << '\n';
    }
    for (const auto& str : changed_tests) {
        std::cout << str << '\n';
    }
}
