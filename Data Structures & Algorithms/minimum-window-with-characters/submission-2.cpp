class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int>targetFreq;
        for(auto c : t){
            targetFreq[c]++;
        }
        int required = targetFreq.size();
        int formed =0;
        int left =0, right =0;
        unordered_map<char, int> windowFreq;
        int minLen = INT_MAX;
        int minLeft =0;

        while ( right < s.size()){
            char c = s[right];
            windowFreq[c]++;

            if(targetFreq.count(c) && windowFreq[c] == targetFreq[c]){
                formed++;
            }

            while(left <= right && formed == required){
                if ((right-left+1) < minLen){
                    minLen = right-left+1;
                    minLeft = left;
                }

                char leftChar = s[left];
                windowFreq[leftChar]--;

                if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar]){
                    formed --;
                }
                left++;
            }
            right++;
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
        
    }
};
