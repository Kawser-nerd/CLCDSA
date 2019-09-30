#include<stdio.h>
#include<stdlib.h>
int star[1024][2];

int star2cmp(const void*a,const void*b){
int*c=(int*)a,*d=(int*)b;
if(c[1]==d[1])return 0;
return c[1]>d[1]?1:-1;
}

int main(int argc,char*argv[]){
	int a,b,c,e,f,earned,ans;
	scanf("%d",&f);
	for(e=1;e<=f;e++){
		scanf("%d",&c);
		for(a=0;a<c;a++){
			scanf("%d%d",star[a]+0,star[a]+1);
		}
		qsort(star,c,sizeof(int)*2,star2cmp);

		earned=0;
		ans=0;
		for(a=0;a<c;a++){
			while(earned<star[a][1]){

				for(b=c-1;b>=a;b--){
					if(earned>=star[b][0]&&star[b][0]!=-100)break;
				}
				if(b<a)goto toobad;
				star[b][0]=-100;
				ans++;
				earned++;
			}
			earned++;
			if(star[a][0]!=-100)earned++;
			ans++;
		}
		printf("Case #%d: %d\n",e,ans);
		continue;
		toobad:
		printf("Case #%d: Too Bad\n",e);
	}
	return 0;
}
