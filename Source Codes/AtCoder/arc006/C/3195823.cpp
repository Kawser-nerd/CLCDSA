#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

int main(){

    int N,tmp;
    int max;
    int ans = 0;

    cin >> N;
    vector<int> v(N);
    vector<bool> checked(N);
    for(int i = 0; i < N; ++i){
        cin >> tmp;
        v[i] = tmp;
        checked[i] = false;
    }

 //   sort(v.begin(), v.end(), greater<int>());
    max = *max_element(v.begin(), v.end());

    while(count(checked.begin(), checked.end(), false)){
        tmp = max + 1;
        for(int i = 0; i < v.size(); ++ i){
            if(checked[i] == false && v[i] <= tmp){
                checked[i] = true;
                tmp = v[i];
            }
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}