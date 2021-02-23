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

/*
 Load Average: 1.79, 1.70, 1.49
 ---------------------------------------------------------
 Benchmark               Time             CPU   Iterations
 ---------------------------------------------------------
 BM_Matching/1        1105 ns         1104 ns       636723
 BM_Matching/10      18600 ns        18587 ns        63177
 BM_Matching_BigO    9852.67 (1)     9845.36 (1)
 BM_Matching_RMS         89 %            89 %
 */

static void BM_Matching(benchmark::State& state) {
    OrderPoolBuilder order_pool;
    for (auto _: state) {
        state.PauseTiming();
//        order_pool.init_orders((int)state.range(1000000), 22.9, 23.3, 100, false);
        order_pool.init_orders(1000000, 22.9, 23.3, 100, false);
        state.ResumeTiming();
        order_pool.run_matching(100000, false);
    }
}

//BENCHMARK(BM_Matching)->Arg(1)->Arg(10)->Complexity();
BENCHMARK(BM_Matching);
BENCHMARK_MAIN();
