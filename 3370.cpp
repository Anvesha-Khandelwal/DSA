#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    int smallestNumber(int n) {
        for (int i = 0; i <= 11; i++) {
            int x = pow(2, i) - 1;
            if (x >= n) {
                return x;
            }
        }
        return -1;
    }
};

int main() {
    Solution obj;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Smallest number of the form (2^i - 1) >= " << n << " is: "
         << obj.smallestNumber(n) << endl;
    return 0;
}
