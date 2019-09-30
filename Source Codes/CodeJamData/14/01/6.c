#include<stdio.h>

int main(int argc,char*argv[]){
	int a,b,c,d,e,f;
	int r1[16],r2[16];
	scanf("%d",&e);
	for(f=1;f<=e;f++){
		scanf("%d",&c);
		for(a=0;a<16;a++){
			scanf("%d",&b);
			r1[b-1]=a/4;
		}
		scanf("%d",&d);
		for(a=0;a<16;a++){
			scanf("%d",&b);
			r2[b-1]=a/4;
		}
		c--;
		d--;
		b=-1;
		for(a=0;a<16&&b!=-2;a++){
			if(r1[a]==c&&r2[a]==d){
				if(b>=0)b=-2;
				if(b==-1)b=a;
			}
		}
		printf("Case #%d: ",f);
		if(b==-1)puts("Volunteer cheated!");
		if(b==-2)puts("Bad magician!");
		if(b>=0)printf("%d\n",b+1);
	}
	return 0;
}
