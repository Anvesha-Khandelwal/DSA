#include <iostream>
using namespace std;

int main() {

    long long n;
    cin >> n;
    int count =0 ;
    while(n!=0){
        n /= 5;
        count = count +n;

    }
 cout<<count;
    return 0;
}