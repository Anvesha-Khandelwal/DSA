#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        long long n, m;
        cin >> n >> m;
        vector<long long> a(m);
        for(int i = 0; i < m; i++){
            cin >> a[i];
        }

        bool hasNonIncreasing = false;
        for(int i = 0; i + 1 < m; i++){
            if(a[i] >= a[i+1]){
                hasNonIncreasing = true;
                break;
            }
        }

        if(hasNonIncreasing){
            
            cout << 1 << "\n";
        } else {
            long long r = a[m-1];
            cout << (n - r + 1) << "\n";
        }
    }

    return 0;
}
