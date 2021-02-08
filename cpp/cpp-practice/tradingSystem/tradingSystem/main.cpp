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
    int quantity;
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
    Order ord1 {"ord1", 17.3, 1, 1, 0};
    Order ord2 {"ord2", 16.2, 1, 2, 0};
    Order ord3 {"ord3", 18.2, 2, 1, 0};

    buy_q.push(ord1);
    buy_q.push(ord2);
    buy_q.push(ord3);
    
    Order ord1_ {"ord1", 13.3, 2, 1, 1};
    Order ord2_ {"ord2", 16.2, 1, 2, 1};
    Order ord3_ {"ord3", 16.2, 3, 1, 1};

    sell_q.push(ord1_);
    sell_q.push(ord2_);
    sell_q.push(ord3_);

}

void printBQ(priority_queue<Order, vector<Order>, PriceCompareDesc> q) {
    while (!q.empty()) {
        Order ord = q.top();
        q.pop();
        printf("orderID -> %s, price -> %f, time -> %ld, direction -> %d",
               ord.order_id.c_str(), ord.price, ord.time, ord.direction);
        cout << endl;

    }
}

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

void trading_simulation() {
    while (!buy_q.empty()) {
        Order buy_ord = buy_q.top();
        buy_q.pop();
        
        string order_id = buy_ord.order_id;
        int buy_quantity = buy_ord.quantity;
        double buy_price = buy_ord.price;
        int total_quantity = buy_quantity;
        double total_cost = 0.0;
        
        while (!sell_q.empty()) {
            Order sell_ord = sell_q.top();
            sell_q.pop();
            if (sell_ord.price <= buy_price) {
                if (buy_quantity > sell_ord.quantity) {
                    // buy order partially filled
                    total_cost += sell_ord.quantity * sell_ord.price;
                    buy_quantity -= sell_ord.quantity;
                    buy_ord.quantity = buy_quantity - sell_ord.quantity;
                    // push back unfilled buy order
                    buy_q.push(buy_ord);
                } else if (buy_quantity == sell_ord.quantity) {
                    // buy and sell order fully filled
                    total_cost += sell_ord.quantity * sell_ord.price;
                    buy_quantity = 0;
                } else {
                    // sell order partially fulfilled
                    total_cost += buy_quantity * sell_ord.price;
                    buy_quantity = 0;
                    sell_ord.quantity = sell_ord.quantity - buy_quantity;
                    // push back unfilled sell order
                    sell_q.push(sell_ord);
                }
            } else {
                cout << "[error] minimum sell price is larger than maximum buy price" << endl;
                break;
            }
            
            if (buy_quantity == 0) break;
        }
        double buy_avg_price = total_cost/total_quantity;
        cout << "order id: " << order_id << " filled with price: " << buy_avg_price << endl;
        
    }
}

void printSQ(priority_queue<Order, vector<Order>, PriceCompareAsc> q) {
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

    printBQ(buy_q);
    cout << endl;
    printSQ(sell_q);
    
    cout << "trading simulation ..." << endl;
    trading_simulation();
    return 0;
}
