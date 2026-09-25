class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        unordered_map<char, int> strS;
        unordered_map<char, int> strT;

        for(int i = 0; i< s.length(); i++){
            strS[s[i]]++;
            strT[t[i]]++;
        }
        return strS == strT;
 
    }
};
