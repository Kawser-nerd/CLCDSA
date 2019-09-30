#include <stdio.h>

typedef long long ll;

char S[100005][15];
int MARCH[5];

int main() {

	int N;

	scanf("%d",&N);

	int i,j,k;

	for(i=0;i<N;i++){
	scanf("%s",&S[i]);
	if(S[i][0]=='M'){MARCH[0]++;}
	if(S[i][0]=='A'){MARCH[1]++;}
	if(S[i][0]=='R'){MARCH[2]++;}
	if(S[i][0]=='C'){MARCH[3]++;}
	if(S[i][0]=='H'){MARCH[4]++;}
	}

	ll ans=0ll;

	for(i=0;i<=3;i++){
		for(j=i+1;j<=4;j++){
			ll add=1ll;
			for(k=0;k<=4;k++){
				if(k!=i&&k!=j){
				add*=MARCH[k];
				}
			}
			ans+=add;
		}
	}

	printf("%lld\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[15]’ [-Wformat=]
  scanf("%s",&S[i]);
        ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&S[i]);
  ^