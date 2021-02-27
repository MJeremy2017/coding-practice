//
//  main.cpp
//  tweetsTimeline
//
//  Created by Yue Zhang on 24/2/21.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <tuple>
#define LOG(X) cout << X << endl;
using namespace::std;

const string root = "/Users/yuezhang/Workspace/github/leetcoding/cpp/cpp-practice/tweetsTimeline/desc/";

vector<vector<string>> read_csv(const string& file_name, int n_col) {
    int row_cnt = 0;
    const string file_path = root + file_name;
    ifstream file;
    file.open(file_path);
    
    vector<vector<string>> res;
    string line;
    while (getline(file, line)) {
        vector<string> row;
        stringstream s(line);
        string word;
        
        int cols_cnt = n_col;
        while (getline(s, word, ',') && cols_cnt > 0) {
            cols_cnt--;
            row.push_back(word);
        }
        assert(row.size() == n_col);
        res.push_back(row);
        row_cnt++;
    }
    
    file.close();
    cout << "succesfully processed " << row_cnt << " lines" << endl;
    return res;
}

map<string, string> get_users(vector<vector<string>>& users) {
    map<string, string> user_mp;
    for (int i=0; i<users.size(); ++i) {
        user_mp[users[i][0]] = users[i][2];
    }
    return user_mp;
}

map<string, vector<string>> get_follows(vector<vector<string>>& follows) {
    map<string, vector<string>> follow_mp;
    for (int i=0; i<follows.size(); ++i) {
        follow_mp[follows[i][0]].push_back(follows[i][1]);
    }
    return follow_mp;
}

void print_follows(const string& user_id, map<string, vector<string>> follow_mp) {
    int cnt = 0;
    auto dest_users = follow_mp[user_id];
    cout << "src_user_id: " << user_id << " follows: " << endl;
    for (auto user:dest_users) {
        cout << "dest_user_id: " << user << endl;
        cnt++;
    }
    cout << "total: " << cnt << endl;
}

struct tweets {
    string tweet_id;
    string user_id;
    long timestamp;
    string tweet;
};

// get the sorted tweets in timestamp of each user
// user_id -> vector sorted tweets

bool tweet_compare(tweets t1, tweets t2) {
    return t1.timestamp > t2.timestamp;
}

// return1: a map of user_id -> vector of tweets
// return2: a map of tweet_id -> user_id
pair<map<string, vector<tweets>>, map<string, string>> get_user_tweets(vector<vector<string>>& twets) {
    map<string, vector<tweets>> user_tweet;
    map<string, string> tid_2_uid;
    
    for (int i=0; i<twets.size(); ++i) {
        tweets s_tweet;
        s_tweet.tweet_id = twets[i][0];
        s_tweet.user_id = twets[i][1];
        s_tweet.timestamp = stol(twets[i][2]);
        s_tweet.tweet = twets[i][3];
        
        user_tweet[twets[i][1]].push_back(s_tweet);
        tid_2_uid[twets[i][0]] =twets[i][1];
    }
    
    
    for (map<string, vector<tweets>>::iterator it=user_tweet.begin(); it!=user_tweet.end(); ++it) {
        vector<tweets> v_tweets = it->second;
        // sort tweets by time desc
        sort(v_tweets.begin(), v_tweets.end(), tweet_compare);
    }
    
    return make_pair(user_tweet, tid_2_uid);
}

void print_user_tweets(const string& user_id, map<string, vector<tweets>> user_tweets) {
    vector<tweets> twets = user_tweets[user_id];
    for (int i=0; i<twets.size(); ++i) {
        cout << "timestamp: " << twets[i].timestamp << " tweets:\n" << twets[i].tweet << endl;
        cout << endl;
    }
}

struct ret_tweets {
    string display_name;
    long creation_time;
    string tweet;
};

class Compare {
public:
    bool operator() (tweets t1, tweets t2) {
        return t1.timestamp < t2.timestamp;
    }
};

vector<ret_tweets> get_N_tweets(const string& user_id, int len,
                              map<string, string> user_mp,
                              map<string, vector<string>> follow_mp,
                              map<string, vector<tweets>> user_tweets,
                              map<string, string> tid2uid) {
    
    // assume the user follows M users and required length is N, complexity would be Nlog(M)
    // as each time would insert a new tweet to the priority queue
    
    vector<string> dest_users = follow_mp[user_id];
    // put all dest_users' top tweets in a priority queue
    priority_queue<tweets, vector<tweets>, Compare> tweets_q;
    map<string, int> dest_users_index;
    
    cout << "size: " << dest_users.size() << endl;
    for (int i=0; i<dest_users.size(); ++i) {
        // some user with no tweets
        if (user_tweets[dest_users[i]].size() > 0) {
            tweets_q.push(user_tweets[dest_users[i]][0]);
            dest_users_index[dest_users[i]] = 1;
        }
    }
    
    vector<ret_tweets> ans;
    while (len > 0 && !tweets_q.empty()) {
        tweets t = tweets_q.top();
        ret_tweets ret_t;
        ret_t.display_name = user_mp[t.user_id];
        ret_t.creation_time = t.timestamp;
        ret_t.tweet = t.tweet;
        ans.push_back(ret_t);
        // one tweet constructed, pop the top tweet
        tweets_q.pop();
        
        string tid = t.tweet_id;
        string uid = tid2uid[tid];
        // take the user whose tweet has been used and move up to its next tweet
        vector<tweets> v_tweets = user_tweets[uid];
        int index = dest_users_index[uid];
        if (v_tweets.size() > index) {
            tweets_q.push(v_tweets[index]);
            dest_users_index[uid] = index + 1;
        }
        len--;
    }
    
    return ans;
}

int main() {
    // insert code here...
    // get map of user_id -> display name
    // get map of src_user_id -> list of dest_user_id
    // get map of user_id -> list of tweets sorted by time
    // given user and timeline, get sorted top of its followings' tweets

    // load files
    const string user_file = "users.csv";
    const string follows_file = "follows.csv";
    const string tweets_file = "tweets.csv";
    
    vector<vector<string>> users = read_csv(user_file, 3);
    auto user_mp = get_users(users);
//    cout << "user_id: " << users[3][0] << " display name: " << user_mp[users[3][0]] << endl;

    vector<vector<string>> follows = read_csv(follows_file, 2);
    auto follow_mp = get_follows(follows);
//    print_follows(follows[3][0], follow_mp);

    vector<vector<string>> twets = read_csv(tweets_file, 4);
    auto res = get_user_tweets(twets);
    map<string, vector<tweets>> user_tweets = res.first;
    map<string, string> tid2uid = res.second;
//    print_user_tweets(users[3][0], user_tweets);


    string test_uid = "989489610";
    auto ans = get_N_tweets(test_uid, 10, user_mp, follow_mp, user_tweets, tid2uid);
    for (int i=(int)ans.size()-1; i>=0; --i) {
        ret_tweets s_t = ans[i];
        cout << "display name: "<< s_t.display_name << endl;
        cout << "creation time: "<< s_t.creation_time << endl;
        cout << "tweet: "<< s_t.tweet << endl;
    }
        
    return 0;
}
