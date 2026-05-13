#include <iostream>
using namespace std;

void hanoi(int n, int from, int helper, int to) {

    // base case
    if(n == 1) {
        cout << from << " " << to << endl;
        return;
    }

    hanoi(n - 1, from, to, helper);
    cout << from << " " << to << endl;

   
    hanoi(n - 1, helper, from, to);
}

int main() {

    int n;
    cin >> n;

    cout << ((1LL << n) - 1) << endl;

    hanoi(n, 1, 2, 3);

    return 0;
}