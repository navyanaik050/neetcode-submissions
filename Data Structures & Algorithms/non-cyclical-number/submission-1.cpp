class Solution {
public:
    bool isHappy(int n) {
        
        int slow = n, fast = sumOfSquares(n);
        while(slow != fast){
            fast = sumOfSquares(fast);
            fast = sumOfSquares(fast);
            slow = sumOfSquares(slow);
        }
        return fast == 1;
    }

    int sumOfSquares(int n){
        int op = 0;
        while(n != 0){
            op += (n % 10) * (n % 10);
            n /= 10;
        }
        return op;
    }
};
