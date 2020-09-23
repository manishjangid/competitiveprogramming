#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'segments' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING message as parameter.
 */
 //MACROS for input
const int MAX_MSG_LEN = 160;
const int MSG_SGMNT_LEN = 155;
//Time Complexity :O(n * k) where n is length of the string message and
// k is size of maximum cut which we make to copy it to output string ie 160

vector<string> segments(string message) {
    // Calculate msg len
    int msg_len = message.size();
    int sgmnt = 0;
    int space_idx;
    // To keep track of current character in message
    int curr_char_pointer = 0;
    int total_segments = 0;
    // For temporary copy purpose 
    string msg_to_add;
    // to store final segments
    vector<string> segments;

    // base case if msg len is 0, return empty segments
    if (msg_len == 0) {
        return segments;
    }
    cout<<msg_len<<endl;

    // No need of introducting segments if msg len is less than equal to 160
    if (msg_len <= MAX_MSG_LEN) {
        segments.push_back(message);
        return segments;
    }

    // total segments excluding the last one
    total_segments = (msg_len / MSG_SGMNT_LEN);

    // To handle 3rd case, divide based on the last space in the segment
    // and then take action 
    for (sgmnt = 1; sgmnt <= total_segments; sgmnt++) {
        // split based on length 155
        msg_to_add = message.substr(curr_char_pointer, MSG_SGMNT_LEN);

        space_idx = msg_to_add.find_last_of(" ");

        // If no space found space_idx is set to end_idx
        if (space_idx == -1) {
            space_idx = MSG_SGMNT_LEN - 1;
        }
        // Space find will give index where space is found, if space is not found at the last index ie 154
        // then we need to split again upto the space point and then continue
        if (space_idx != (MSG_SGMNT_LEN - 1)) {
            msg_to_add = message.substr(curr_char_pointer, space_idx + 1);
        }
        // add suffix
        msg_to_add += "(" + std::to_string(sgmnt) + "/" + std::to_string((total_segments + 1)) + ")";
        segments.push_back(msg_to_add);
        curr_char_pointer += (space_idx + 1);
    }
    // For the last segment
    if ((curr_char_pointer + 1) != msg_len) {
        msg_to_add = message.substr(curr_char_pointer, MSG_SGMNT_LEN);
        msg_to_add += "(" + std::to_string(sgmnt) + "/" + std::to_string((total_segments + 1)) + ")";
        segments.push_back(msg_to_add);

    }
  
    return segments;
}

int main() {
    string message = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa manish komal anushree";
    string message2 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    vector<string> sgmnts = segments(message2);
    for (int idx = 0; idx < sgmnts.size(); idx++) {
        cout<<sgmnts[idx]<<endl;
    }
    return 0;
}