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
//#include <benchmark/benchmark.h>
using namespace std;

int main() {
    // insert code here...
    
    OrderPoolBuilder order_pool;
    order_pool.init_orders(10000000, 21.2, 23.3, 1000, false);

    cout << "trading simulation ..." << endl;
    long start = time(0);
    order_pool.run_matching(100000, false);
    
    cout << "time cost: " << time(0) - start << endl;
    return 0;
}
