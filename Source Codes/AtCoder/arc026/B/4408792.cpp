#include <iostream>
#include <cstdlib>
#include <vector>
#include <map>

using namespace std;

int main() {
    using ll = long long;
    
    ll n;
    cin >> n;
    
    ll sum = 0;
    
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;   
        
            if (i * i != n) {
                sum += n / i;   
            }
        }
    }
    
    sum -= n;
    
    if (sum == n) {
        cout << "Perfect" << endl;   
    } else if (sum < n) {
        cout << "Deficient" << endl;   
    } else {
        cout << "Abundant" << endl;   
    }
}