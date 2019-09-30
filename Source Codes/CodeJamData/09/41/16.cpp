#include<cstdio>
#include<algorithm>

using namespace std;

int T,i,n,j,num[100],I;
char s[1000];

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d",&n);
		for (i=0;i<n;++i){
			scanf(" %s",s);
			num[i]=-1;
			for (j=0;s[j];++j)
				if (s[j]=='1') num[i]=j;
		}
		int ans=0;
		for (i=0;i<n;++i){
			for (j=i;j<n;++j)
				if (num[j]<=i) break;
			for (;j>i;--j) swap(num[j],num[j-1]),++ans;
		}
		printf("Case #%d: %d\n",++I,ans);
	}
}
