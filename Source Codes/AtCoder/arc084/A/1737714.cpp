#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;

int n;
int a[108000];
int b[108000];
int c[108000];



int main(){
	cin >> n;
	for(int i = 0;i < n;i++)cin >> a[i];
	for(int i = 0;i < n;i++)cin >> b[i];
	for(int i = 0;i < n;i++){
		cin >> c[i];
		c[i] = -c[i];
	}

	sort(a, a + n);
	sort(b, b + n);
	sort(c, c + n);

	Int res = 0;
	for(int i = 0;i < n;i++){
		Int acnt = lower_bound(a, a + n, b[i]) - a;
		acnt = max(acnt, 0LL);

		Int ccnt = lower_bound(c, c + n, -b[i]) - c;
		ccnt = max(ccnt, 0LL);
		
		res += acnt * ccnt;
	}
	
	cout << res << endl;
	return 0;
}