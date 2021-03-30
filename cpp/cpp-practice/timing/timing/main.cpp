//
//  main.cpp
//  timing
//
//  Created by Yue Zhang on 30/3/21.
//

#include <iostream>
#include <chrono>
#include <thread>

struct Timer {
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;
    
    Timer() {
        start = std::chrono::high_resolution_clock::now();
    }
    
    ~Timer() {
        end = std::chrono::high_resolution_clock::now();
        duration = end - start;
        std::cout << "duration: " << duration.count()*1000.0f << "ms" << std::endl;
    }
};

// function to measure time
void func() {
    Timer t;
    
    for (int i=0; i<100; ++i) {
        std::cout << i << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    using namespace std::chrono_literals;
   
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(1s);
    auto end = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<float> duration = end - start;
    std::cout << duration.count() << std::endl;
    
    // measure time
    func();
    return 0;
}
