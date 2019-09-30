#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

int a[510][510];
int n;

bool check(int x,int y,int v){
	if (x<0 || x>2*n || y<0 || y>2*n) return true;
	if (a[x][y]==-1) return true;
	return a[x][y]==v;
}

int T,I,i,j,k,l,ans;

int main(){
	scanf("%d",&T);
	while (T--){
		printf("Case #%d: ",++I);
		scanf("%d",&n);
		memset(a,-1,sizeof a);
		for (i=0;i<n;++i)
			for (k=0;k<=i;++k)
			    scanf("%d",&a[i][k*2+n-i-1]);
		for (i=n-2;i>=0;--i)
		    for (k=0;k<=i;++k)
		        scanf("%d",&a[n*2-i-2][k*2+n-i-1]);
		ans=n*100;
		for (i=0;i<n*2;++i)
		    for (j=0;j<n*2;++j)
		        if (1){
					int tmp=0;
					bool bt=1;
		            for (k=0;k<n*2;++k)
		                for (l=0;l<n*2;++l)
		                    if (a[k][l]==-1) continue;
		                    else if (!(check(2*i-k,l,a[k][l]) && check(2*i-k,2*j-l,a[k][l])
								&& check(k,l,a[k][l]) && check(k,2*j-l,a[k][l]))){
									bt=0;
									break;
							}
							else{
								tmp=max(tmp,abs(i-k)+abs(j-l));
							}
					if (bt) ans=min(ans,tmp);
				}
		++ans;
		printf("%d\n",ans*ans-n*n);
	}
}
