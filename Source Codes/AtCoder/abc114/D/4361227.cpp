#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    int N;
    cin >> N;
    //N???????????????
    vector<int> prime;
    prime.push_back(2);
    bool flag = true;
    for (int i = 3;i<N+1;i++){
        flag = true;
        for (int j = 0;j<prime.size();j++){
            if(i % prime[j] == 0){
                flag = false;
                break;
            }
        }
        if(flag == true){
            prime.push_back(i);
        }
    }
    //N!????????
    int b;
    int p = 0;
    int a[prime.size()];
    int k;
    for (int i = 0;i<prime.size();i++){
        for (int j = 1;j < N+1;j++){
            k = j;
            b = j % prime[i];
            k = k / prime[i];
            while(b == 0){
                b = k % prime[i];
                p = p + 1;
                k = k / prime[i];
            }
        }
        a[i] = p;
        p = 0;
    }
    int psize = prime.size();
    bool fl2 = true,fl4 = true,fl14 = true,fl24 = true,fl74 = true;
    int t2 = 0,t4 = 0,t14 = 0,t24 = 0,t74 = 0;
    for (int i = 0;i< psize;i++){
        if(a[psize-i-1] >= 2){
            if(fl2 == true){
                t2 = psize - i;
            }
            fl2 = false;
        }
        if(a[psize-i-1] >= 4){
            if(fl4 == true){
                t4 = psize - i;
            }
            fl4 = false;
        }
        if(a[psize-i-1] >= 14){
            if(fl14 == true){
                t14 = psize - i;
            }
            fl14 = false;
        }
        if(a[psize-i-1] >= 24){
            if(fl24 == true){
                t24 = psize - i;
            }
            fl24 = false;
        }
        if(a[psize-i-1] >= 74){
            if(fl74 == true){
                t74 = psize - i;
            }
            fl74 = false;
        }
    }
    int ans = t74 + (t2 - 1)*(t24) + (t4 - 1)*(t14) + (t2 - 2)*(t4 - 1)*(t4)/2;
    cout << ans << endl;
}