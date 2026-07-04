# Rates Desk Simulator

CMake-baseret C++20 skeleton til en rates desk simulator.

Projektet er delt op i:

- `include/` og `src/`: quant-biblioteket `rates_lib`
- `app/main.cpp`: tynd CLI/simulator
- `tests/`: simple `assert`-baserede tests indtil du eventuelt tilfoejer Catch2 eller GoogleTest
- `data/`: eksempeldata til kurver og klientforespoergsler

## Build

Standard-presets bruger `Unix Makefiles`, som virker med Apples command line tools:

```sh
cmake --preset debug
cmake --build --preset debug
```

Hvis du installerer Ninja, kan du bruge:

```sh
cmake --preset debug-ninja
cmake --build --preset debug-ninja
```

## Test

```sh
ctest --preset debug
```

## Kør simulatoren

```sh
./build/debug/rates_desk
```
brug shift+control+F5