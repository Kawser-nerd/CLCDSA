#include<iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int n, k, x, y, sum = 0;
    cin >> n >> k >> x >> y;
    for(int i=1; i <= n;++i){
        if(i<=k){
            sum += x;
        }
        else{
            sum += y;
        }
    }
    cout << sum << endl;
}