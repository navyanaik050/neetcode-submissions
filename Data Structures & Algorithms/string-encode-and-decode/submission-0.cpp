#include <bits/stdc++.h>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded_result;

        for(auto c : strs){
            int length = c.size();
            encoded_result.append(reinterpret_cast<const char*>(&length), sizeof(int));
            encoded_result.append(c);
        }
        return encoded_result;

    }

    vector<string> decode(string s) {
        vector<string> decoded_string;
        int current_pos = 0;
        int total_length = s.size();

        while(current_pos < total_length){
            int string_length = 0;
            memcpy(&string_length, s.data()+current_pos, sizeof(int));
            current_pos += sizeof(int);

            decoded_string.push_back(s.substr(current_pos, string_length));
            current_pos += string_length;

        }

        return decoded_string;
    }
};
