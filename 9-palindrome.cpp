class Solution {
public:
    bool isPalindrome(int x) {
       
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int original = x;
        long long ans = 0; 
        int digit;

        while (x != 0) {
            digit = x % 10;
            ans = ans * 10 + digit;
            x /= 10;
        }

        return ans == original;
    }
};
