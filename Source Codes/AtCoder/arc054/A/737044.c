#include<stdio.h>
main(){
	int l,x,y,s,d;
	double t1,t2,t3,t4;
	scanf("%d %d %d %d %d",&l,&x,&y,&s,&d);
	if(s-d==0){
		printf("0\n");
	}else{
		if(s<d){
			t1=(double)(d-s)/(double)(x+y);
			if(x<y){
				t2=(double)(l+s-d)/(double)(y-x);
				if(t1<=t2){
					printf("%f\n",t1);
				}else{
					printf("%f\n",t2);
				}
			}else{
				printf("%f\n",t1);
			}
		}else{
			t3=(double)(l+d-s)/(double)(x+y);
			if(x<y){
				t4=(double)(s-d)/(double)(y-x);
				if(t3<=t4){
					printf("%f\n",t3);
				}else{
					printf("%f\n",t4);
				}
			}else{
				printf("%f\n",t3);
			}
		}
	}
	return 0;
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d %d",&l,&x,&y,&s,&d);
  ^