#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long pow(int a, int b, int mod)
{
	int ret = 1;
	for(int i = 0 ; i < b ; i ++){
		ret = ret * a % mod;
	}
	return ret;
}

int main(void){
	long long n;
	cin>>n;
	vector<int> v(n);
	for(int i = 0 ; i < n ; i ++){
		cin>>v[i];
	}

 	int s = n-1;
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	if (n % 2 == 1) v.push_back(0);

 	bool flag = true;
	for(int i = 0 ; i < n ; i ++){
		int a = v[i++];
		int b = v[i];
		if (a != s || b != s || a != b){
			flag = false;
			break;
		}
		s -= 2;
	}

	if (flag) cout<<pow(2, n/2, 1000000007)<<endl;
	else cout<<0<<endl;
}