 /* Created on Fri Aug 28 2020
 *
 * Copyright (c) 2020 Manish Kumar
 */

// INSERTION SORT 
// TIME COMPLEXITY O(n^2) : when the input is given in decreasing order (Upper Bound)
// SPACE COMPLEXITY O(1) : excluding auxiliary space needed to store input array 
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void insertion_sort(vector<int>& input) {
    int idx = 1;
    int idx2 = 0;
    int key = 0;
    int sz = input.size();

    while (idx < sz) {

        key = input[idx];
        idx2 = idx - 1;

        while (idx2 >= 0 && input[idx2] > key) {
            input[idx2 + 1] = input[idx2];
            idx2 = idx2 - 1;
        }
        input[idx2 + 1] = key;
        idx++;
    }
    for (int idx = 0; idx < (int)input.size(); idx++) {
        cout << input[idx] << " ";
    }
}
int main(int argc, char *argv[]) {

    vector<int> input;

    for (int idx = 1; idx < argc; idx++) {
        input.push_back(stoi(argv[idx]));
    }

    insertion_sort(input);
    cout<<endl;
    return 0;
}