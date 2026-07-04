#include "rates/io/CsvReader.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace rates::io {

std::vector<std::vector<std::string>> CsvReader::read(const std::string& path) const
{
    std::ifstream file(path);

    if (!file) {
        std::cerr << "Fejl i aabning af filen " << path << ".\n";
        return {};
    }

    std::vector<std::vector<std::string>> rows;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream line_stream(line);
        std::string cell;

        while (std::getline(line_stream, cell, ',')) {
            row.push_back(cell);
        }

        rows.push_back(row);
    }

    return rows;
}

} // namespace rates::io