#include <iostream>
#include <climits> // for INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;

            // Check for overflow before multiplying by 10
            if (ans > INT_MAX / 10 || ans < INT_MIN / 10) {
                return 0;
            }

            ans = ans * 10 + digit;
            x = x / 10;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    cout << "Reversed integer: " << obj.reverse(n) << endl;
    return 0;
}
