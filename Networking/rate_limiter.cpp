 /* Created on Fri Aug 28 2020
 *
 * Copyright (c) 2020 Manish Kumar
 */

// INSERTION SORT 
// TIME COMPLEXITY : TBD
// SPACE COMPLEXITY O(2n) ~ O(n) : excluding auxiliary space needed to store input array 
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

class Solution {
        queue<int> q_60;
        queue<int> q_10;
        unordered_map<int, int> hmap;

    public:

        Solution() {
            hmap.clear();
        }

        bool will_request_drop (int timestamp) {
            int ts;
            uint8_t drop = 0;

            // verify if the timestamp is now old enough to delete the entries before 10 seconds
            while (!q_10.empty()) {
                ts = q_10.front();

                if (timestamp - 10 >= ts) {
                    q_10.pop();
                } else {
                    break;
                }
            }

            // verify if timestamp is old enough to delete the entries older than 60 seconds
            while (!q_60.empty()) {
                ts = q_60.front();

                if (timestamp - 10 >= ts) {
                    q_60.pop();
                } else {
                    break;
                }
            }

            q_60.push(timestamp);
            q_10.push(timestamp);

            if (hmap.find(timestamp) != hmap.end()) {
                hmap[timestamp]++;

                if (hmap[timestamp] > 3) {
                    drop = 1;
                }
            } else {
                hmap.clear();
                hmap[timestamp] = 1;    
            }
                
            if (!drop) {
                if (q_10.size() > 20) {
                    drop = 1;
                }
            }

            if (!drop) {
                if (q_60.size() > 60) {
                    drop = 1;
                }
            }

            return drop;
        }
};

int main(int argc, char *argv[]) {
    vector<int> input;
    int drop_count = 0;

    Solution *sol = new Solution();

    for (int idx = 1; idx < argc; idx++) {
        drop_count += sol->will_request_drop(stoi(argv[idx]));
    }

    cout<<"Total Count : "<<argc - 1 <<" Drop Count is "<<drop_count<<endl;
    delete sol;
    return 0;
}