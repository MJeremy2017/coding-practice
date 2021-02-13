//
//  LongQBuilder.cpp
//  tradingSystem
//
//  Created by Yue Zhang on 13/2/21.
//

#pragma once
#include <stdio.h>
#include "order.h"
#include <queue>


class QBuilder {
public:
    // buy order ordered by price descending
    priority_queue<Order, vector<Order>, PriceCompareDesc> buy_q;
    // sell order ordered by price
    priority_queue<Order, vector<Order>, PriceCompareAsc> sell_q;

    void add_buy_order(Order ord) {
        if (ord.direction != 1) return;
        if (buy_q.empty()) {
            buy_q.push(ord);
            return;
        }
        if (ord.price < sell_q.top().price) return;
        buy_q.push(ord);
    }
    
    void add_sell_order(Order ord) {
        if (ord.direction != 0) return;
        if (sell_q.empty()) {
            sell_q.push(ord);
            return;
        }
        if (ord.price > buy_q.top().price) return;
        sell_q.push(ord);
    }

};

