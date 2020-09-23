 /* Created on Fri Aug 29 2020
 *
 * Copyright (c) 2020 Manish Kumar
 */

#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
    public:
        Solution() {
        }

        static bool compare_func(vector<int>& first, vector<int>& second) {
            return first[0] < second[0];
        }

        static bool compare_func2(vector<int>& first, vector<int>& second) {
            return first[1] < second[1];
        }

        int get_max_companies(vector<int> arrival, vector<int> duration) {
            vector<vector<int>> input;
            int sz = arrival.size();
            int idx = 0;

            if (sz == 0) {
                return 0;
            }

            for (idx = 0; idx < sz; idx++) {
                input.push_back({arrival[idx], arrival[idx] + duration[idx]});
            }

            sort(input.begin(), input.end(), compare_func);
            priority_queue<vector<int>, vector<vector<int>>, decltype(&compare_func)> pqueue(compare_func);

            pqueue.push({1,3});
            pqueue.push({1,5});
            pqueue.push({1,10});

            while (!pqueue.empty()) {
                vector<int> el = pqueue.top();

                cout<<"testing "<<el[0]<<" "<<el[1]<<endl;
                pqueue.pop();
            }

            for (auto elem: input) {
                cout<<"size is "<<pqueue.size()<<endl;
                if (pqueue.empty()) {
                    pqueue.push(elem);
                } else {
                    vector<int> topelem = pqueue.top();

                    if (topelem[0] == elem[0]) {
                        if (elem[0] < topelem[0]) {
                            pqueue.pop();
                            pqueue.push(elem);
                        }
                    } else {

                        if (elem[1] <= topelem[1]) {
                                pqueue.pop();
                                pqueue.push(elem);
                        }
                        else if (topelem[1] <= elem[0]) {
                            pqueue.push(elem);
                        }
                    }
                }
            }
            return pqueue.size();
        }
};

int main(int argc, char *argv[]) {
    vector<int> arrival({978,409,229,934,299,982,636,14,866,815,64,537,426,670,116,95,630});
    vector<int> duration({502,518,196,106,405,452,299,189,124,506,883,753,567,717,338,439,145});

    cout<<arrival.size()<<" "<<duration.size();

    Solution sol = Solution();

    cout<<"Total companies are "<<sol.get_max_companies(arrival, duration)<<endl;
    return 0;
} 