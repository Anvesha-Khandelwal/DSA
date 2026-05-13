#include <iostream>
using namespace std;

int main() {

    string s;
    cin >> s;

    int count = 1;
    int maxi = 1;

    for(int i = 1; i < s.length(); i++) {

        if(s[i] == s[i-1]) {
            count++;
        }

        else {
            count = 1;
        }

        maxi = max(maxi, count);
    }

    cout << maxi;

    return 0;
}