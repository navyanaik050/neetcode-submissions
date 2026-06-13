class Solution {
public:
    bool isPalindrome(string s) {
        return resultFunction(s, 0, s.length()-1);
        
    }
    bool resultFunction(string s, int i, int size){
        if( i >= size){
            return true;
        }
        if(!isalnum(s[i])){
            return resultFunction(s, i+1, size);
        } else if(!isalnum(s[size])){
            return resultFunction(s, i, size-1);
        } else if((tolower(s[i])) != (tolower(s[size]))){
            return false;
        }
        return resultFunction(s, i+1, size-1 );
    }
};
