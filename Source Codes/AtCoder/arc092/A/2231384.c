#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}

ll d[210];
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,2*n){
		int x,y;
		scanf("%d%d",&x,&y);
		d[i]=x*2000+y*2+(i/n);
	}
	sortup(d,2*n);
	ll ans=0;
	rep(i,0,2*n)if(d[i]%2){
		int index=-1;
		int ymax=-1;
		int iy=d[i]%2000/2;
		rep(j,0,i)if(d[j]%2==0){
			int jy=d[j]%2000/2;
			if(jy<iy&&jy>ymax){
				ymax=jy;
				index=j;
			}
		}
		if(ymax!=-1){
			ans++;
			d[index]=-1;
		}
		d[i]=-1;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&x,&y);
   ^