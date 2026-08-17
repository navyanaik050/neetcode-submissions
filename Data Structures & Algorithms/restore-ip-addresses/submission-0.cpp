class Solution {
public:
    vector<string>res;

    vector<string> restoreIpAddresses(string s) {
        if(s.length() > 12) return res;
        backTrack(s, 0, 0, "");
        return res;
    }
    
    void backTrack(string& s,int i, int dot, string curIp){
        if(dot == 4 && i == s.size()){
            res.push_back(curIp.substr(0, curIp.size()-1));
            return;
        }
        if(dot > 4){
            return;
        }
        for(int j = i; j< min(i+3, (int)s.size()); j++){
            if(i != j && s[i] == '0') continue;
            if(stoi(s.substr(i, j-i+1 ))< 256){
                backTrack(s, j+1, dot+1, curIp+s.substr(i, j-i+1)+".");
            }
        }
    }
};