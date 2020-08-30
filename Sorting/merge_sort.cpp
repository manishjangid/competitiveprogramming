 /* Created on Fri Aug 29 2020
 *
 * Copyright (c) 2020 Manish Kumar
 */

// MERGE SORT 
// TIME COMPLEXITY O(n * log(n)) : when the input is given in decreasing order (Upper Bound)
// SPACE COMPLEXITY O(n) : excluding auxiliary space needed to store input array
#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;

int *temp_array; //Global for this instance 
int sz_of_arr = 0;

void merge(vector<int>& list, int start, int mid, int end) {
    int l1_start = start;
    int l2_start = mid + 1;
    int temp_idx = 0;

    while (l1_start <= mid && l2_start <= end) {
        if (list[l1_start] < list[l2_start]) {
            temp_array[temp_idx++] = list[l1_start++]; 
        } else {
            temp_array[temp_idx++] = list[l2_start++];
        }
    }
    while (l1_start <= mid) {
        temp_array[temp_idx++] = list[l1_start++];
    }

    while (l2_start <= end) {
        temp_array[temp_idx++] = list[l2_start++];
    }

    // copy to original array
    for (l2_start = 0; l2_start < temp_idx; l2_start++) {
        list[start++] = temp_array[l2_start];
    }
}

void merge_sort(vector<int>& list, int start, int end) {
    int mid;
    if (start < end) {
        mid = (start + end) / 2;

        merge_sort(list, start, mid);
        merge_sort(list, mid + 1, end);
        merge(list, start, mid, end);
    }
}

int main(int argc, char *argv[]) {

    vector<int> input;

    for (int idx = 1; idx < argc; idx++) {
        input.push_back(stoi(argv[idx]));
    }

    if (input.size() == 0) {
        return -1;
    }
    sz_of_arr = input.size();
    temp_array = new int(sz_of_arr);

    if (temp_array == NULL) {
        cout<<"Memory allocation failed" <<endl;
        return -2;
    }
    memset(temp_array, 0, sizeof(int) * sz_of_arr);

    merge_sort(input, 0, sz_of_arr - 1);

    for (int idx = 0; idx < sz_of_arr; idx++) {
        cout<<input[idx]<<" ";
    }
    cout<<endl;
    return 0;
}