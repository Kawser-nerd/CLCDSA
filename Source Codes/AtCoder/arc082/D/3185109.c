#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

ll left[100010],right[100010];
ll leftV[100010],rightV[100010];

ll t[100010];
ll v,k;
int main(){
	scanf("%lld%lld",&v,&k);
	rep(i,1,k+1)scanf("%lld",t+i);
	left[0]=0,leftV[0]=0;
	right[0]=v,rightV[0]=v;
	
	//???
	//???????????
	rep(i,1,k+1){
		//????a???ti?????????????
		//(0,leftV)-(left,leftV)-(right,rightV)-(v,rightV)
		//?4????????????? _/¯ ? ¯\_ ???
		//???ti????left,leftV,right,rightV????
		ll time=t[i]-t[i-1];
		if(i%2){
			//??ti????_/¯
			if(rightV[i-1]<=time){
				//?????
				left[i]=v,leftV[i]=v;
				right[i]=v,rightV[i]=v;
			}else if(leftV[i-1]>=time){
				//????????
				left[i]=left[i-1],leftV[i]=v-(leftV[i-1]-time);
				right[i]=right[i-1],rightV[i]=v-(rightV[i-1]-time);
			}else{
				//left???????
				left[i]=left[i-1]+(time-leftV[i-1]);leftV[i]=v;
				right[i]=right[i-1];rightV[i]=v-(rightV[i-1]-time);
			}
		}else{
			//??ti????¯\_
			if(leftV[i-1]<=time){
				//?????
				left[i]=v,leftV[i]=v;
				right[i]=v,rightV[i]=v;
			}else if(rightV[i-1]>=time){
				//????????
				left[i]=left[i-1],leftV[i]=v-(leftV[i-1]-time);
				right[i]=right[i-1],rightV[i]=v-(rightV[i-1]-time);
			}else{
				//right???????
				left[i]=left[i-1];leftV[i]=v-(leftV[i-1]-time);
				right[i]=right[i-1]-(time-rightV[i-1]);rightV[i]=v;
			}
		}
	}
	
//	rep(i,0,k+1)printf("%lld %lld %lld %lld\n",left[i],leftV[i],right[i],rightV[i]);
	
	ll q;
	scanf("%lld",&q);
	while(q--){
		ll time;
		ll a;
		scanf("%lld%lld",&time,&a);
		//time?????[t_i,t_{i+1})?????????
		ll l=0,r=k+1;
		while(r-l>1){
			ll m=(l+r)/2;
			if(t[m]<=time)l=m;
			else r=m;
		}
//		printf("%lld ",l);
		time-=t[l];
		ll ans;
		
		if(a<=left[l]){
			ans=max(leftV[l]-time,0);
		}else if(a>=right[l]){
			ans=max(rightV[l]-time,0);
		}else{
			if(l%2){
				//¯\_
				ans=max(leftV[l]-(a-left[l])-time,0);
			}else{
				//_/¯
				ans=max(leftV[l]+(a-left[l])-time,0);
			}
		}
		printf("%lld\n",l%2?v-ans:ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld",&v,&k);
  ^
./Main.c:13:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,k+1)scanf("%lld",t+i);
              ^
./Main.c:61:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&q);
  ^
./Main.c:65:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&time,&a);
   ^