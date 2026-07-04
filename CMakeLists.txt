cmake_minimum_required(VERSION 3.20)

project(RatesDeskSimulator
    VERSION 0.1.0
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(rates_lib
    src/core/Date.cpp
    src/core/DayCount.cpp
    src/core/CashFlow.cpp
    src/core/Schedule.cpp

    src/market/YieldCurve.cpp
    src/market/MarketData.cpp

    src/products/Swap.cpp
    src/products/SwapLeg.cpp
    src/products/Trade.cpp

    src/pricing/SwapPricer.cpp
    src/pricing/RiskCalculator.cpp
    src/pricing/Discounting.cpp

    src/desk/QuoteEngine.cpp
    src/desk/HedgeEngine.cpp
    src/desk/PnlEngine.cpp

    src/io/CsvReader.cpp
    src/io/ReportPrinter.cpp
)

target_include_directories(rates_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(rates_lib
    PUBLIC
        cxx_std_20
)

add_executable(rates_desk
    app/main.cpp
)

target_link_libraries(rates_desk
    PRIVATE
        rates_lib
)

enable_testing()

add_executable(rates_tests
    tests/test_yield_curve.cpp
    tests/test_swap_pricer.cpp
    tests/test_quote_engine.cpp
    tests/test_risk.cpp
)

target_link_libraries(rates_tests
    PRIVATE
        rates_lib
)

add_test(NAME RatesTests COMMAND rates_tests)
