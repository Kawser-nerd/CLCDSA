#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <numeric>
#include <array>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);i++)

long long int bag_size[51];
long long int num_patty[51];
long long int count_patty(long long n, long long x){
    if(n==0&&x==1) return 1;
    else if(x <= 1) return 0;
    else if(x <= 1 + bag_size[n-1]) return count_patty(n-1,x-1);
    else if(x == 2 + bag_size[n-1]) return 1 + num_patty[n-1];
    else if(x <= 2 + bag_size[n-1]*2) return 1 + num_patty[n-1] + count_patty(n-1, x-2-bag_size[n-1]);
    else return 1 + num_patty[n-1]*2;
}

int main(){
    long long int n,x; cin >> n >> x;
    rep(i,51){
        if(i==0){
            bag_size[i] = 1;
            num_patty[i]=1;
        }
        else{
            bag_size[i] = 3 + 2 * bag_size[i-1];
            num_patty[i] = 1 + 2 * num_patty[i-1];
        }
    }
    cout << count_patty(n,x) << endl;
    return 0;
}