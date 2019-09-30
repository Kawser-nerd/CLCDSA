#include<stdio.h>
int m[50][50],h,w;

void swapint(int*c,int*d){
	int k;
	k=c[0];
	c[0]=d[0];
	d[0]=k;
}
void printboard(int i,int x,int y){
	int a,b;
	if(i==1){
		swapint(&x,&y);
		swapint(&h,&w);
		for(a=0;a<h;a++){
			for(b=a+1;b<h;b++){
				swapint(m[a]+b,m[b]+a);
			}
		}
	}
	for(a=0;a<h;a++){
		for(b=0;b<w;b++){
			if(a==x&&b==y)putchar('c');
			else if(m[a][b]==0)putchar('*');
			else putchar('.');
		}
		putchar('\n');
	}
}
void clearboard(){
	int a,b;
	for(a=0;a<h;a++){
		for(b=0;b<w;b++){
			m[a][b]=0;
		}
	}
}
void fillanswer(int c,int d,int n){
	int a,b;
	for(a=0;a<c;a++)m[a][0]=m[a][1]=1;
	for(b=0;b<d;b++)m[0][b]=m[1][b]=1;
	n-=(a*2+b*2-4);
	for(a=2;a<c&&n>0;a++){
		for(b=2;b<d&&n>0;b++){
			m[a][b]=1;
			n--;
		}
	}
}

int main(int argc,char*argv[]){
	int a,b,t2,t,n,ans[2],inv;
	scanf("%d",&t2);
	for(t=1;t<=t2;t++){
		scanf("%d%d%d",&h,&w,&n);
		printf("Case #%d:\n",t);
		n=h*w-n;
		if(h>w){
			inv=1;
			swapint(&h,&w);
		}
		else inv=0;
		clearboard();
		ans[0]=ans[1]=0;
		if(h==1){/*special case 1*/
			for(b=0;b<n;b++)m[0][b]=1;
			goto yes;
		}
		if(n==1)goto yes;/*special case 2*/
		if(n==2||n==3)goto no;
		if(h==2&&n%2==1)goto no;/*special case 3*/
		for(a=2;a<=h;a++){
			for(b=2;b<=w;b++){
				if(a*2+b*2-4>n)break;
				if(a*b<n)continue;
				fillanswer(a,b,n);
				goto yes;
			}
		}
		no:
		puts("Impossible");
		continue;
		yes:
		printboard(inv,ans[0],ans[1]);
	}
	return 0;
}
