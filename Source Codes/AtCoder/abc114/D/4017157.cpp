#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);i++)
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int main(){
    //75 = 5 * 5 * 3; x^4 * y^4 * z^2; x^14 * y^4; x^24 * y^2; 2^74;
    int n; cin >> n;
    int num_prime[25];
    rep(i,25){
        int temn=n;
        int temc=0;
        while(temn!=0){
            temc += temn / prime[i];
            temn = temn / prime[i];
        }
        num_prime[i] = temc;
    }
    int ans = 0;
    for(int i=0;i<25;i++) for(int j=i+1;j<25;j++) for(int k=j+1;k<25;k++){
        if(num_prime[i] >= 4 && num_prime[j]>=4 && num_prime[k] >= 2) ans++;
        if(num_prime[i] >= 4 && num_prime[j]>=2 && num_prime[k] >= 4) ans++;
        if(num_prime[i] >= 2 && num_prime[j]>=4 && num_prime[k] >= 4) ans++;
    }
    for(int i=0;i<25;i++) for(int j=i+1;j<25;j++){
        if(num_prime[i] >= 14 && num_prime[j]>=4) ans++;
        if(num_prime[i] >= 24 && num_prime[j]>=2) ans++;
        if(num_prime[i] >= 4 && num_prime[j]>=14) ans++;
        if(num_prime[i] >= 2 && num_prime[j]>=24) ans++;
    }
    for(int i=0;i<25;i++){
        if(num_prime[i] >= 74) ans++;
    }
    cout << ans << endl;
    return 0;
}