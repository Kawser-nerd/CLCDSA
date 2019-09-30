#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    int h[N];
    for(int i= 0;i<N;i++){
        cin >> h[i];
    }
    int sum = 0;
    for(int i = 0;i<N;i++){
        sum = sum + h[i];
    }
    sort(h,h+N);
    int q;
    bool flag = false;
    for (int i = 0;i<N;i++){
        if(h[i] % 10 != 0){
            q = h[i];
            flag = true;
            break;
        }
    }
    if(sum % 10 != 0){
        cout << sum << endl;
    }
    else{
        if(flag == true){
            cout << sum - q << endl;
        }
        else{
            cout << 0 << endl;
        }
    }
}