//
//  main.cpp
//  tradingSystem
//
//  Created by Yue Zhang on 7/2/21.
//

#include <iostream>
#include <vector>
#include <queue>
#include "OrderPool.hpp"
#include "log.hpp"
#include <ctime>
#include <benchmark/benchmark.h>
#include "Timer.hpp"
using namespace std;
#define LOG(x) cout << x << endl;


static void BM_Matching(benchmark::State& state) {
    OrderPoolBuilder order_pool;
    for (auto _: state) {
        state.PauseTiming();
        order_pool.init_orders((int)state.range(0), 21.2, 23.3, 100, false);
        state.ResumeTiming();
        order_pool.run_matching(1, false);
    }
}

BENCHMARK(BM_Matching)->Arg(1)->Arg(10)->Complexity();
BENCHMARK_MAIN();
