class Solution {
public:
    string minWindow(string s, string t) {
/*        unordered_map<char, int>targetFreq;
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
            right--;
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);*/
                unordered_map<char, int> targetFreq;
        for (char c : t) {
            targetFreq[c]++;
        }

        // Total unique characters required to match
        int required = targetFreq.size();

        // Sliding window pointers
        int left = 0, right = 0;

        // Counter to track how many unique characters in window match target
        int formed = 0;

        // Frequency map for characters in the current window
        unordered_map<char, int> windowFreq;

        // Track the minimum window length and its starting index
        int minLen = INT_MAX;
        int minLeft = 0;

        // Expand the window by moving right pointer
        while (right < s.size()) {
            // Add the current character into window
            char c = s[right];
            windowFreq[c]++;

            // If current character is in target and frequency matches, increase formed
            if (targetFreq.count(c) && windowFreq[c] == targetFreq[c]) {
                formed++;
            }

            // Try shrinking the window from the left
            while (left <= right && formed == required) {
                // Update the minimum window if this is smaller
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }

                // Remove the left character from window
                char leftChar = s[left];
                windowFreq[leftChar]--;

                // If leftChar is part of target and falls below required count, decrease formed
                if (targetFreq.count(leftChar) && windowFreq[leftChar] < targetFreq[leftChar]) {
                    formed--;
                }

                // Move the left pointer forward
                left++;
            }

            // Expand the window to the right
            right++;
        }

        // Return the minimum window substring, or empty if not found
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    
        
    }
};
