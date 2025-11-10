class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending with 0 (except 0 itself) cannot be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int original = x;
        long long ans = 0; // use long long to avoid overflow
        int digit;

        while (x != 0) {
            digit = x % 10;
            ans = ans * 10 + digit;
            x /= 10;
        }

        return ans == original;
    }
};
