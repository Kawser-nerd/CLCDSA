#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))

char s[9000];
ll d[9000];
ll xx[20000],*x=xx+10000;
ll yy[20000],*y=yy+10000;
ll tt[20000],*t=tt+10000;

int main(){
	scanf("%s",s);
	int len=strlen(s);
	
	int cnt=0;
	rep(i,0,len){
		if(s[i]=='F')d[cnt]++;
		else cnt++;
	}
	cnt++;
	
	x[d[0]]=1;
	repp(i,2,cnt,2)if(d[i]){
		//x
		rep(k,-8500,8500){
			t[k]=0;
			if(abs(k+d[i])<8500)t[k]|=x[k+d[i]];
			if(abs(k-d[i])<8500)t[k]|=x[k-d[i]];
		}
		rep(k,-8500,8500)x[k]=t[k];
	}
	
	y[0]=1;
	repp(i,1,cnt,2)if(d[i]){
		//y
		rep(k,-8500,8500){
			t[k]=0;
			if(abs(k+d[i])<8500)t[k]|=y[k+d[i]];
			if(abs(k-d[i])<8500)t[k]|=y[k-d[i]];
		}
		rep(k,-8500,8500)y[k]=t[k];
	}
		
	int p,q;
	scanf("%d%d",&p,&q);
	puts(x[p]&y[q]?"Yes":"No");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^
./Main.c:48:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&p,&q);
  ^