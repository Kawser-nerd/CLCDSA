#include <stdio.h>
#include <string.h>

char S[100005];

int max(int a,int b){
	if(a>b){return a;}
	else{return b;}
}

int main() {

	scanf("%s",S);

	int T;

	scanf("%d",&T);

	int len=strlen(S);

	int i;

	int pos_x=0;
	int pos_y=0;
	int q=0;

	for(i=0;i<len;i++){
		if(S[i]=='L'){pos_x--;}
		else if(S[i]=='R'){pos_x++;}
		else if(S[i]=='U'){pos_y++;}
		else if(S[i]=='D'){pos_y--;}
		else{q++;}
	}

	int ans;

	if(T==1){
		ans=max(pos_x,-pos_x)+max(pos_y,-pos_y)+q;
	}
	else{
		for(i=0;i<q;i++){
			if(pos_x>0){pos_x--;}
			else if(pos_x<0){pos_x++;}
			else if(pos_y>0){pos_y--;}
			else if(pos_y<0){pos_y++;}
			else{pos_x++;}
		}
		ans=max(pos_x,-pos_x)+max(pos_y,-pos_y);
	}
	printf("%d\n",ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&T);
  ^