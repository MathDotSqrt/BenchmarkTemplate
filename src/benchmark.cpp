#include <benchmark/benchmark.h>

//Testing default constructor
static void benchmark_func1(benchmark::State& state) {
    for (auto _ : state)
        std::string empty_string;
}

//Testing copy constructor
static void benchmark_func2(benchmark::State& state) {
    std::string x = "hello";
    for (auto _ : state) {
        std::string copy(x);
    }
}

//Testing copy constructor and "reads" the memory
static void benchmark_func3(benchmark::State& state) {
    std::string x = "hello";
    for (auto _ : state) {
        std::string copy(x);
        
        //Please read the section on preventing your entire benchmark from being optimized away
        //https://github.com/google/benchmark/blob/main/docs/user_guide.md#preventing-optimization
        // Force the compiler to flush pending writes to global memory. Acts as an
        // effective read/write barrier
        benchmark::ClobberMemory();
    }
}

//Documentation: https://github.com/google/benchmark/blob/main/docs/user_guide.md
//run all benchmarks in release build
BENCHMARK(benchmark_func1);
BENCHMARK(benchmark_func2);
BENCHMARK(benchmark_func3);

BENCHMARK_MAIN();