#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <iterator>
#include <bitset>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

char a[1111][1111];
double WP[1111],OWP[1111],OOWP[1111],RPI[1111];
int n;
void work(){
	cin >> n;
	for (int i=0;i<n;i++)
		scanf("%s",a[i]);
	for (int i=0;i<n;i++){
		int cnt1=0,cnt2=0;
		for (int j=0;j<n;j++)
			if (a[i][j]=='1') cnt1++;
			else if (a[i][j]=='0') cnt2++;
		WP[i]=cnt1/(double)(cnt2+cnt1);
	}
	for (int i=0;i<n;i++){
		int cnt1=0;
		double cnt2=0;
		for (int j=0;j<n;j++)
			if (a[i][j]=='1'||a[i][j]=='0'){
				cnt1++;
				int c1=0;
				int c2=0;
				for (int k=0;k<n;k++){
					if (k==i) continue;
					if (a[j][k]=='1') c1++;
					else if (a[j][k]=='0') c2++;
				}
				cnt2+=c1/(double)(c1+c2);
			}
		OWP[i]=cnt2/(double)(cnt1);
	}
	for (int i=0;i<n;i++){
		int cnt1=0;
		double cnt2=0;
		for (int j=0;j<n;j++)
			if (a[i][j]=='1'||a[i][j]=='0'){
				cnt1++;
				cnt2+=OWP[j];
			}
		OOWP[i]=cnt2/(double)(cnt1);
	}
	for (int i=0;i<n;i++) {
		RPI[i]=0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i];
		printf("%.15lf\n",RPI[i]);
	}
	
}

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int t;cin >> t;
	for (int i=1;i<=t;i++){
		cout << "Case #"<< i << ":" <<endl;
		work();
	}
	//system("pause");
	return 0;
}
/*
2
3
.10
0.1
10.
4
.11.
0.00
01.1
.10.
*/

