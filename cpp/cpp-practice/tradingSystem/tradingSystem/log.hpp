//
//  log.hpp
//  tradingSystem
//
//  Created by Yue Zhang on 13/2/21.
//

#ifndef log_hpp
#define log_hpp

#include <stdio.h>
#include "order.h"
#include "PriceCompare.hpp"
#include <queue>

void printBQ(priority_queue<Order, vector<Order>, PriceCompareDesc> q);

#endif /* log_hpp */
