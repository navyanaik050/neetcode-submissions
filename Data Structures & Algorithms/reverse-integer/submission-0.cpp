class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            if( res > INT_MAX/10 || res < INT_MIN/10){
                return 0;
            }

            int lastDigit = x % 10;
            res = res * 10 + lastDigit;
            x /= 10;
        }
        return res;   
    }
};
