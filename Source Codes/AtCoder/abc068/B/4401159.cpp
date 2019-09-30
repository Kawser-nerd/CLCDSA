#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>

using namespace std;

#define ll long long

int main(){
    int N, ans = 1;
    cin >> N;
    while(ans <= N){
        ans *= 2;
    }
    ans /= 2;
    if(ans == 0) ans = 1;
    cout << ans << endl;
}