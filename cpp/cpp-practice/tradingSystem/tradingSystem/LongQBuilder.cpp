//
//  LongQBuilder.cpp
//  tradingSystem
//
//  Created by Yue Zhang on 13/2/21.
//

#include <stdio.h>
#include "order.cpp"
#include <queue>


class PriceCompareDesc {
public:
    bool operator() (Order ord1, Order ord2) {
        if (ord1.price != ord2.price) return ord1.price < ord2.price;
        else return ord1.time > ord2.time;
    }
};


class LongQBuilder {
public:
    // buy order ordered by price descending
    priority_queue<Order, vector<Order>, PriceCompareDesc> buy_q;
    
    void add_order(Order ord) {
        if (ord.direction != 1) return;
        if (buy_q.empty()) {
            buy_q.push(ord);
            return;
        }
        if (ord.price < sell_q.top().price) return;
        buy_q.push(ord);
    }

}

