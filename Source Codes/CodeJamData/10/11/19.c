#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	int t,n,k,i,j,p,x,y,xx,red=0,blue=0;
	char b[50][50],c,*o;
	FILE *fp1=fopen("A-small.in","r");
	FILE *fp2=fopen("A-small.out","w");
	memset(b,0,sizeof(b));
	fscanf(fp1,"%d",&t);
	for(i=1;i<=t;i++){
		fscanf(fp1,"%d%d",&n,&k);
		for(j=0;j<n;j++){
			fscanf(fp1,"%s",b[j]);
		}
		for(x=0;x<n;x++){
			for(p=n-1,y=n-1;y>=0;){
				while(y>=0 && b[x][y]=='.')y--;
				if(y<0)break;
				if(p>y){
					b[x][p]=b[x][y];
					b[x][y]='.';
				}
				p--;y--;
			}
		}
		red=0,blue=0;
//-
		for(x=0;(!(red&&blue)) && x<n;x++){
			for(y=0;y<=n-k;y++){
				c=b[x][y];
				if(c=='.')continue;
				for(j=1;j<k;j++){
					if(b[x][y+j]!=c)goto no1;
				}
				if(c=='R')red=1;else blue=1;
				continue;
		no1:    y=y+j-1;
			}
		}
//|
		for(y=0;(!(red&&blue)) && y<n;y++){
			for(x=0;x<=n-k;x++){
				c=b[x][y];
				if(c=='.')continue;
				for(j=1;j<k;j++){
					if(b[x+j][y]!=c)goto no2;
				}
				if(c=='R')red=1;else blue=1;
				continue;
		no2:    x=x+j-1;
			}
		}
///
		for(x=k-1;(!(red&&blue)) && x<2*n-k;x++){
			xx=x;
			for(y=0;y<=n-k && x>=k-1;y++,x--){
				if(x>=n)continue;
				c=b[x][y];
				if(c=='.')continue;
				for(j=1;j<k;j++){
					if(b[x-j][y+j]!=c)goto no3;
				}
				if(c=='R')red=1;else blue=1;
				continue;
		no3:    x=x-j+1,y=y+j-1;
			}
			x=xx;
		}
///
		for(x=-n+1;(!(red&&blue)) && x<=n-k;x++){
			xx=x;
			for(y=0;x<=n-k && y<=n-k;y++,x++){
				if(x<0){
					x=-1;
					y=-1-xx;
					continue;
				}
				c=b[x][y];
				if(c=='.')continue;
				for(j=1;j<k;j++){
					if(b[x+j][y+j]!=c)goto no4;
				}
				if(c=='R')red=1;else blue=1;
				continue;
		no4:    x=x+j+1,y=y+j-1;
			}
			x=xx;
		}

		if(red==1 && blue==1)o="Both";
		else if(red==1 && blue==0)o="Red";
		else if(red==0 && blue==1)o="Blue";
		else o="Neither";
		fprintf(fp2,"Case #%d: %s\n",i,o);
	}
	fclose(fp1);
	fclose(fp2);
	return 0;
}

