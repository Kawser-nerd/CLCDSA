#include <stdio.h>

typedef long long ll;

ll s[100005];

int main(){

	int N;

	ll K;

	scanf("%d %lld",&N,&K);

	int i;

	int flag=0;

	for(i=0;i<N;i++){
		scanf("%lld",&s[i]);
		if(s[i]==0ll){flag=1;}
	}
	if(flag==1){
		printf("%d\n",N);
		return 0;
	}

	int l,r;

	l=0;
	r=1;

	ll sum=s[0];

	int ans=0;

	if(sum<=K){
		if(ans==0){ans=1;}
	}

	while(1){
		if(r==N){break;}
		if(sum*s[r]<=K){
			sum*=s[r];
			if(ans<r-l+1){ans=r-l+1;}
			r++;
		}
		else{
			sum/=s[l];
			l++;
		}
		if(l==r){
			r++;
			sum=s[l];
			if(sum<=K){
				if(ans==0){ans=1;}
			}
		}
	}

	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %lld",&N,&K);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&s[i]);
   ^