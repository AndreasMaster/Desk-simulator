#pragma once

#include <ostream>
#include <string>

namespace rates::io {

class ReportPrinter {
public:
    void print_line(std::ostream& out, const std::string& line) const;
};

} // namespace rates::io
