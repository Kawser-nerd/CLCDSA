#include<stdio.h>
char s[30][30]={};
int X[]={1,1,0,-1};
int Y[]={0,1,1,1};
int chack(){
	int i,j,k,l,r=0,ny,nx;
	for(i=1;i<20;i++){
		for(j=1;j<20;j++){
			if(s[i][j]=='.')continue;
			for(k=0;k<4;k++){
				for(l=1;l<5;l++){
					ny=i+Y[k]*l;
					nx=j+X[k]*l;
					if(s[i][j]-s[ny][nx])break;
				}
				if(l==5)r|=(s[i][j]=='o'?1:2);
			}
		}
	}
	return r;
}
int main(){
	int i,j,b=0,w=0,r;
	char c;
	for(i=0;i<19;i++){
		scanf("%s",s[i+1]+1);
		for(j=0;j<19;j++){
			if(s[i+1][j+1]=='o')b++;
			if(s[i+1][j+1]=='x')w++;
		}
	}
	r=chack();//printf("%d\n",r);
	if(b<w||b>w+1||r>2||b>w&&r==2||b==w&&r==1){
		printf("NO\n");
		return 0;
	}
	if(r==0){
		printf("YES\n");
		return 0;
	}//printf("a\n");
	for(i=1;i<20;i++){
		for(j=1;j<20;j++){
			c=s[i][j];
			if(c-(r==1?'o':'x'))continue;
			s[i][j]='.';
			r=chack();
			if(r==0)goto END;
			s[i][j]=c;
		}
	}
	printf("NO\n");
	return 0;
	END:;
	printf("YES\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s[i+1]+1);
   ^