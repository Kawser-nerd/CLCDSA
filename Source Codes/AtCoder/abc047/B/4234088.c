#include<stdio.h>

int main(){
	int W,H,N;
	scanf("%d%d%d",&W,&H,&N);
	int w1=0,w2=W,h1=0,h2=H,x,y,a;
	while(N--){
		scanf("%d%d%d",&x,&y,&a);
		if(a==1){
			if(x<w1){
				continue;
			}
			w1=x;
		}
		else if(a==2){
			if(w2<x){
				continue;
			}
			w2=x;
		}
		else if(a==3){
			if(h1>y){
				continue;
			}
			h1=y;
		}
		else if(a==4){
			if(h2<y){
				continue;
			}
			h2=y;
		}
	}
	int p,o;
	p=w2-w1;
	if(p<=0){
		p=0;
	}
	o=h2-h1;
	if(o<=0){
		o=0;
	}
	if(o*p<=0){
		printf("0");
	}
	else{
		printf("%d",o*p);
	}
	
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&W,&H,&N);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&x,&y,&a);
   ^