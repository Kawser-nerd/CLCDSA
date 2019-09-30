#include<stdio.h>
char in[55][55];
int mx[4]={1,1,1,0},my[4]={-1,0,1,1};
int main(){
	int t,n,k,i,j,q,w,cas=1;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(i=0;i<n;i++){
			scanf("%s",&in[i]);
			int c=n-1;
			for(j=n-1;j>=0;j--)if(in[i][j]!='.')in[i][c--]=in[i][j];
			for(j=c;j>=0;j--)in[i][j]='.';
		}
		bool rw=0,bw=0;
		for(i=0;i<n;i++)for(j=0;j<n;j++){
			if(in[i][j]=='.')continue;
			char c=in[i][j];
			for(q=0;q<4;q++){
				int ii=i,jj=j;
				for(w=0;w<k;w++){
					if(ii<0||ii>=n||jj<0||jj>=n)break;
					if(in[ii][jj]!=c)break;
					ii+=mx[q];jj+=my[q];
				}
				if(w==k){
					if(c=='R')rw=1;
					else bw=1;
					break;
				}
			}
		}
		printf("Case #%d: ",cas++);
		if(rw){
			if(bw)puts("Both");
			else puts("Red");
		}else{
			if(bw)puts("Blue");
			else puts("Neither");
		}
	}
}
