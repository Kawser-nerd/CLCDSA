#include<iostream>
using namespace std;

int main(){
	int n,m; cin >> n >> m;
  	int ans;
  	for(int i=1;i<100000;i++){
      if(m % i == 0 && m/i >= n) ans = ans < i ? i : ans;
      if(m % i == 0 && i >= n) ans = ans < m/i ? m/i : ans;
    }
	cout << ans << endl;
  	return 0;
}