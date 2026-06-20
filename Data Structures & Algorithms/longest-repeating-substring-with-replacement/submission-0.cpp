class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map <char, int> freq;
        int max_freq = 0;
        int max_length =0;
        int left =0;
        for(int right=0; right< s.size(); right++){
            freq[s[right]]++;
            max_freq =max(freq[s[right]], max_freq);
            while ( (right - left +1)- max_freq > k){
                freq[s[left]]--;
                left ++;
            }
            max_length = max(max_length, right - left +1 );
        }

        return max_length;
    }
};
