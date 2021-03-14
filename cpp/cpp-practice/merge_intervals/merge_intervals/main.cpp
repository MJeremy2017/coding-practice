//
//  main.cpp
//  merge_intervals
//
//  Created by Yue Zhang on 12/3/21.
//

#include <iostream>
#include <vector>
using namespace std;

bool interval_cmp(vector<int> v1, vector<int> v2) {
    return v1[0] < v2[0];
}

void print_intervals(vector<vector<int>> intervals) {
    for (auto v: intervals) {
        cout << v[0] << " " << v[1] << endl;
    }
}

void merge_intervals(vector<vector<int>> intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end(), interval_cmp);
    
    ans.push_back(intervals[0]);
    for (auto i=1; i<intervals.size(); ++i) {
        int start = ans.back()[0];
        int end = ans.back()[1];
        if (intervals[i][0] <= end && intervals[i][1] > end) {
            ans.pop_back();
            ans.push_back({start, intervals[i][1]});
        } else if (intervals[i][0] > end) {
            ans.push_back(intervals[i]);
        }
    }
    
    print_intervals(ans);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<vector<int>> intervals = { {6,10}, {1,5}, {2,4}, {3,8}, {11,13} };
    
    merge_intervals(intervals);
    
    return 0;
}
