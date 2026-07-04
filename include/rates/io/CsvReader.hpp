#pragma once

#include <string>
#include <vector>

namespace rates::io {

class CsvReader {
public:
    std::vector<std::vector<std::string>> read(const std::string& path) const;
};

} // namespace rates::io
