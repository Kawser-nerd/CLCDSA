#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)

typedef struct edge{ll s,g,c;}E;
 
ll n;
E e[200010];
ll vjisuu[100010];
ll vnow[100010];
ll epre[200010];
 
ll que[200010];
ll d[100010];
void bfs(int k){
	ll qcnt=1;
	ll tooi;
	que[0]=k;
	d[k]=1;
	rep(i,0,qcnt){
		ll v=que[i];
		for(ll t=vnow[v];t!=-1;t=epre[t])if(!d[e[t].g]){
			que[qcnt++]=e[t].g;
			d[e[t].g]=d[v]+1;
		}
	}
}

ll ans[100010];
int main(){
	scanf("%lld",&n);
	rep(i,0,n)vnow[i]=-1;
	
	rep(i,0,n-1){
		ll a,b;
		scanf("%lld%lld",&a,&b);
		a--;b--;
		e[2*i].s=a;
		e[2*i].g=b;
		epre[2*i]=vnow[a];
		vnow[a]=2*i;
		
		e[2*i+1].s=b;
		e[2*i+1].g=a;
		epre[2*i+1]=vnow[b];
		vnow[b]=2*i+1;
		
		vjisuu[a]++;
		vjisuu[b]++;
	}
	
	bfs(0);
	ll tooi1=0;
	rep(i,0,n)if(d[i]>d[tooi1])tooi1=i;
	rep(i,0,n)d[i]=0;
	
	bfs(tooi1);
	ll tooi2=tooi1;
	rep(i,0,n)if(d[i]>d[tooi2])tooi2=i;
	
	//tooi2??tooi1???????????????1??
	ll vr=e[vnow[tooi2]].g;
	ll vpre=tooi2;
	ll len=0;
	while(vr!=tooi1){
//		printf("vr:%d %d\n",vr,d[vr]);
		ll vnext;
		ll cnt=0;
		for(ll t=vnow[vr];t!=-1;t=epre[t]){
			ll vtemp=e[t].g;
//			printf("vtemp:%d %d\n",vtemp,d[vtemp]);
			if(d[vtemp]<d[vr]){
				vnext=vtemp;
			}else if(vtemp!=vpre){
				if(vjisuu[vtemp]!=1){
					puts("-1");
					return 0;
				}
				cnt++;
			}
		}
		ans[len++]=cnt;
		vpre=vr;
		vr=vnext;
	}
	
	int flag=0;
	ll left=0,right=len-1;
	while(left<right&&ans[left]==ans[right])left++,right--;
	
	if(ans[left]>ans[right]){
		//????
		for(ll l=0,r=len-1;l<r;l++,r--){
			ll t=ans[l];
			ans[l]=ans[r];
			ans[r]=t;
		}
	}
	printf("1 ");
	ll crr=1;
	rep(i,0,len){
		rep(j,0,ans[i])printf("%d ",crr+1+j+1);
		printf("%d ",crr+1);
		crr+=ans[i]+1;
	}
	printf("%d ",crr+1);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:105:25: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   rep(j,0,ans[i])printf("%d ",crr+1+j+1);
                         ^
./Main.c:106:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%d ",crr+1);
          ^
./Main.c:109:9: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long long int’ [-Wformat=]
  printf("%d ",crr+1);
         ^
./Main.c:34:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&a,&b);
   ^