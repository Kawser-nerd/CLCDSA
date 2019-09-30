#include <iostream>
using namespace std;

using ull = unsigned long long;

int main(void){
    int n, k;
    cin >> n >> k;
    
    ull arr[n];
    ull sum = 0;
    for(int i = 0; i < n; ++i){ cin >> arr[i]; }

    for(int i = 0; i < n - k + 1; ++i){
        for(int j = 0; j < k; ++j){
            sum += arr[i + j];
        }
    }
        
    cout << sum << endl;
    return 0;
}