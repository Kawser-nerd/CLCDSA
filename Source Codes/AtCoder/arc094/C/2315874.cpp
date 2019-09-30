#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
#define INF (1LL<<30)

Int n;
Int a[216000], b[216000];
int main(){
	cin >> n;
	bool allsame = 1;
	Int minbig = INF;
	Int sum = 0;
	for(int i = 0;i < n;i++){
		cin >> a[i] >> b[i];
		if(a[i] != b[i])allsame = 0;
		if(a[i] > b[i])minbig = min(minbig, b[i]);
		sum += a[i];
	}
	if(allsame)
		cout << 0 << endl;
	else
		cout << sum - minbig << endl;
	return 0;
}