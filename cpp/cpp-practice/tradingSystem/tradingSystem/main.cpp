//
//  main.cpp
//  tradingSystem
//
//  Created by Yue Zhang on 7/2/21.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Order {
    string order_id;
    double price;
    long time;
    int direction;
};

class PriceCompareDesc {
public:
    bool operator() (Order ord1, Order ord2) {
        if (ord1.price != ord2.price) return ord1.price < ord2.price;
        else return ord1.time > ord2.time;
    }
};

class PriceCompareAsc {
public:
    bool operator() (Order ord1, Order ord2) {
        if (ord1.price != ord2.price) return ord2.price < ord1.price;
        else return ord2.time < ord1.time;
    }
};

// buy order ordered by price descending
priority_queue<Order, vector<Order>, PriceCompareDesc> buy_q;

// sell order ordered by price
priority_queue<Order, vector<Order>, PriceCompareAsc> sell_q;

void init() {
    Order ord1 {"ord1", 12.3, 1, 0};
    Order ord2 {"ord2", 15.2, 2, 0};
    Order ord3 {"ord3", 15.2, 1, 0};

    buy_q.push(ord1);
    buy_q.push(ord2);
    buy_q.push(ord3);
}

void printQ(priority_queue<Order, vector<Order>, PriceCompareDesc> q) {
    while (!q.empty()) {
        Order ord = q.top();
        q.pop();
        printf("orderID -> %s, price -> %f, time -> %ld, direction -> %d",
               ord.order_id.c_str(), ord.price, ord.time, ord.direction);
        cout << endl;

    }
}

int main() {
    // insert code here...
    init();
//    cout << buy_q.top().order_id << endl;
    printQ(buy_q);
    
    return 0;
}
