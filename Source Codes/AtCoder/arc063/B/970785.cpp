#include<iostream>
#include<vector>
#include<iomanip>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<queue>
#include<set>
#include<map>
using namespace std;
using ulong = unsigned long;
using ll = long long;
const int M = 1e9 + 7;
#pragma unused(M)

int main(){
	int n, t;
	cin >> n >> t;
    vector<int> as(n);
    int mini = M, diff = -1, ans = 1;
    for(int i=0;i<n;i++){
        // cin >> as[i];
        int a;
        cin >> a;
        mini = min(mini, a);
        if(diff < a - mini){
            diff = a - mini;
            ans = 1;
        }else if(diff == a - mini){
            ans++;
        }
    }
    cout << ans << endl;
	return 0;
}