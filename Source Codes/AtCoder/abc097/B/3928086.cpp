#include <iostream>
using namespace std;

using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
#include <string>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <bitset>
#include <array>
#include <deque>
#include <queue>
#include <map>
#define all(x) (x).begin(),(x).end()

void solve(){

}
int main(){
    int X;
    cin >> X;
    vector<int> v;
    v.push_back(1);
    for (int i = 2; i <= X; i++){
        int k = 2;
        int t = i;
        while(pow(t,k) <= X){
            //cout << t << "**" << k << endl;
            //t = pow(t,k);
            v.push_back(pow(t,k));
            k++;
        }
    }
    cout << *max_element(all(v)) << endl;


    return 0;
}