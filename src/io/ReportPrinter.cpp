#include "rates/io/ReportPrinter.hpp"

namespace rates::io {

void ReportPrinter::print_line(std::ostream& out, const std::string& line) const
{
    out << line << '\n';
}

} // namespace rates::io
