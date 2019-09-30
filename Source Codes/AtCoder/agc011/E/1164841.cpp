#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 500010;
char s[N];
int n,a[N],ans;
int main(){
	//freopen("in.txt","r",stdin);
	n = 0;
	char ch = getchar();
	while (ch >= '0' && ch <= '9'){
		a[n ++] = ch - '0';
		ch = getchar();
	}
	reverse(a,a+n);
	a[n] = 0;
	bool pd = false;
	int pos = n;
	for(int i=n-1;i>=0;i--){
		if(a[i]<a[i+1]){
			if(pd){
				a[0]++;
				for(int j=0;j<pos;j++) 
					if(a[j]>=10){
						a[j+1]++;
						a[j]-=10;
					} else break;
				ans++;
				a[pos]=0;
				pos--;
				//pd=false;
				if(i==pos){
					pd = false;
					pos++;
				} 
				i++;
				
			} else{
				pos = i;
				pd = true;
			}
		
			
		} else {
			if(a[i]>0) pd = true;
			if(a[i]!=a[i+1]) pos = i;
		}
	}
	ans++;
	printf("%d\n",ans);
	return 0;
}
/*
7204647845201772120166980358816078279571541735614841625060678056933503
31
*/