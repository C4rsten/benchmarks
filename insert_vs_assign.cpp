// for execution on quick-bench.com

constexpr size_t container_size = 50;

static void insert(benchmark::State& state) {

  std::vector<int> a(container_size, 10);

  for (auto _ : state) {
    std::vector<int> b;
    b.insert(b.begin(), a.begin(), a.end());
    benchmark::DoNotOptimize(b);
  }
}

static void reserve_insert(benchmark::State& state) {
  
  std::vector<int> a(container_size, 10);

  for (auto _ : state) {
    std::vector<int> b;
    b.reserve(container_size);
    b.insert(b.begin(), a.begin(), a.end());
    benchmark::DoNotOptimize(b);
  }
}

static void assign(benchmark::State& state) {
  
  std::vector<int> a(container_size, 10);

  for (auto _ : state) {
    std::vector<int> b;
    b.assign(a.begin(), a.end());
    benchmark::DoNotOptimize(b);
  }
}

static void reserve_assign(benchmark::State& state) {
  
  std::vector<int> a(container_size, 10);

  for (auto _ : state) {
    std::vector<int> b;
    b.reserve(container_size);
    b.assign(a.begin(), a.end());
    benchmark::DoNotOptimize(b);
  }
}

BENCHMARK(insert);
BENCHMARK(reserve_insert);
BENCHMARK(assign);
BENCHMARK(reserve_assign);
