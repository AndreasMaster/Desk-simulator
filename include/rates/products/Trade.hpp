#pragma once

#include "rates/products/Swap.hpp"

#include <string>

namespace rates::products {

class Trade {
public:
    std::string id{};
    Swap swap{};
};

} // namespace rates::products
