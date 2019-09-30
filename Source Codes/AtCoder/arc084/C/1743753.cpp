#include<iostream>
#include<algorithm>

using namespace std;
int k, n;
int res[1080000];
int main(){
	cin >> k >> n;
	int N = n;
	if(k % 2 == 0){
		cout << k / 2;
		for(int i = 0;i < n - 1;i++)cout << " " << k;
		cout << endl;
		return 0;
	}
	if(k == 1){
	for(int i = 0;i < (n+1)/2;i++)cout << 1 << " " ;
cout << endl;
return 0;
}
	

	for(int i = 0;i < n;i++)res[i] = k/2+1;
	n/=2;
	while(n--){
		int j = 0;
		while(res[j] == 0)j++;
		res[j]--;
		if(res[j] != 0)
			for(int i = 0;i < j;i++)res[i] = k;
		
	}
	for(int i = N-1;i >= 0;i--){
		if(res[i] == 0)break;
		cout << res[i] << " ";
	}
	cout << endl;
	return 0;
}