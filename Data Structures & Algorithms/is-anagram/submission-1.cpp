class Solution {
public:
    bool isAnagram(string s, string t) {
        int size1 = s.size();
        int size2 = t.size();
        if (size1 != size2){
            return false;
        }
/*        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
     
        for(int i=0; i<size1; i++){
            if (s[i] != t[i]){
                return false;
            }
        }
        return true;
    }*/
    int freq[26]= {0};
    for (int i=0; i<size1; i++){
        freq[s[i]-'a']++;
    }
    for(int j=0; j<size2; j++){
        freq[t[j]-'a']--;
    }
    for(int k=0; k<26; k++){
        if (freq[k]!= 0){
            return false;
        }
    }
    return true;
    }
};
