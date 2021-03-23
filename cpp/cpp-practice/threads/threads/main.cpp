//
//  main.cpp
//  threads
//
//  Created by Yue Zhang on 23/3/21.
//

#include <iostream>
#include <thread>
#include <vector>
using namespace std;

static bool is_finished = false;

void DoWork() {
    using namespace literals::chrono_literals;
    cout << "on thread id=" << this_thread::get_id() << endl;
    while (!is_finished) {
        cout << "working" << endl;
        this_thread::sleep_for(1s);
    }
}

void HelloWorld(int a) {
    cout << "value is : " << a << endl;
}

void printValue(int v) {
    cout << "value is: " << v << endl;
}

void ForEach(const vector<int>& values, void(*func)(int)) {
    for (int value: values)
        func(value);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    thread worker(DoWork);
    
    cout << "set finish to true" << endl;
    cin.get();
    is_finished = true;
    cout << "on thread id=" << this_thread::get_id() << endl;
    worker.join();  // wait: after setting finished to true, wait till this thread finish to continue
    
    // func is a function pointer
    auto func = HelloWorld;
    func(11);
    
    vector<int> values = {1, 2, 3, 4};
    ForEach(values, printValue);  // takes in value as a parameter
    
    ForEach(values, [](int v) {cout << "lambda: " << v << endl;});   
    return 0;
}
