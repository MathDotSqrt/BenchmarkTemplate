cmake_minimum_required(VERSION 3.8)
project(BenchmarkTemplate)

set(SOURCE_LIST
	"./src/benchmark.cpp"
)


add_executable(Benchmark ${SOURCE_LIST})

find_package(benchmark REQUIRED)
target_link_libraries(Benchmark benchmark::benchmark)