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
//    order_pool.init_orders(10, 21.2, 23.3, 30, false);
//
//    cout << "trading simulation ..." << endl;
//    long start = time(0);
//    order_pool.run_matching(1, true);
//
//    cout << "time cost: " << time(0) - start << endl;
    
    // simulation
//    order_pool.init_orders(100, 21.2, 23.3, 1000, false);
    int n = 100;
    while (n>0) {
        n--;
        order_pool.init_orders(1, 21.2, 23.3, 1000, true);
        order_pool.run_matching(1, true);

    }
    
    
    return 0;
}
