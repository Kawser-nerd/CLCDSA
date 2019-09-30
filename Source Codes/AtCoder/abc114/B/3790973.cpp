#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll abs(ll a,ll b)
{
	ll c=a-b;
	if(c<0){c=c*-1;}
	return c;
}
int main()
{
	ll s,digi=3;
	cin >> s;

	for(ll i=1000;s/i>0;i=i*10){
		digi++;
	}
	
	ll num[digi],k=0,min=10000;
	for(ll j=digi-1;j>=0;j--){
		num[k] = s/pow(10,j);
		num[k] = num[k] % 10;
		k++;
	}
	/*cout << digi << endl;
	for(int l=0;l<digi;l++){
		cout << num[l] << " ";
	}*/
	
	for(ll m=0;m<digi-2;m++){
		if(min >=
		abs(num[m]*100+num[m+1]*10+num[m+2],753)){min =
			abs(num[m]*100+num[m+1]*10+num[m+2],753);}
	}
	
	cout << min << endl;
	return 0;
}