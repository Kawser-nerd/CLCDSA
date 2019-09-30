#include<stdio.h>

int surmax(int k){
	int r;
	if(k==0)return 0;
	if(k%3==2)r=k/3+2;
	else if(k%3==1)r=k/3+1;
	else r=k/3+1;
	if(r>10)r=10;
	return r;
}

int nonsurmax(int k){
	int r;
	if(k%3==2)r=k/3+1;
	else if(k%3==1)r=k/3+1;
	else r=k/3;
	if(r>10)r=10;
	return r;
}

int main(int argc,char*argv[]){
	int a,b,d,e,n,s,p,g;
	
	scanf("%d",&e);
	for(d=1;d<=e;d++){
		scanf("%d%d%d",&n,&s,&p);
		b=0;
		for(a=0;a<n;a++){
			scanf("%d",&g);
			if(nonsurmax(g)>=p)b++;
			else if(s>0&&surmax(g)>=p){
				s--;
				b++;
			}
		}
		printf("Case #%d: %d\n",d,b);
	}
	return 0;
}
