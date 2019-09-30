#include<stdio.h>

int main(){
	int x1,x2,y1,y2;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	if(x1>=x2&&y1>=x2){
		for(int i=1;i<=(y2-y1);i++){
    		printf("D");
		}
   		for(int i=1;i<=(x2-x1);i++){
    		printf("L");
		}
   		for(int i=1;i<=(y2-y1);i++){
    		printf("U");
		}
    	for(int i=1;i<=(x2-x1);i++){
    		printf("R");
		}
		printf("R");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("D");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("L");
		}
	    printf("U");
	    printf("L");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("U");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("R");
		}
	    printf("D");
	}
	else if(x1<=x2&&y1<=y2){
		for(int i=1;i<=(y2-y1);i++){
    		printf("U");
		}
   		for(int i=1;i<=(x2-x1);i++){
    		printf("R");
		}
   		for(int i=1;i<=(y2-y1);i++){
    		printf("D");
		}
    	for(int i=1;i<=(x2-x1);i++){
    		printf("L");
		}
		printf("L");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("U");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("R");
		}
	    printf("D");
	    printf("R");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("D");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("L");
		}
	    printf("U");
	}
	else if(x1>=x2&&y1<=y2){
		for(int i=1;i<=(y2-y1);i++){
    		printf("U");
		}
   		for(int i=1;i<=(x2-x1);i++){
    		printf("L");
		}
   		for(int i=1;i<=(y2-y1);i++){
    		printf("D");
		}
    	for(int i=1;i<=(x2-x1);i++){
    		printf("R");
		}
		printf("R");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("U");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("L");
		}
	    printf("D");
	    printf("L");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("D");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("R");
		}
	    printf("U");
	}
	else if(x1<=x2&&y1>=y2){
		for(int i=1;i<=(y2-y1);i++){
    		printf("D");
		}
   		for(int i=1;i<=(x2-x1);i++){
    		printf("R");
		}
   		for(int i=1;i<=(y2-y1);i++){
    		printf("U");
		}
    	for(int i=1;i<=(x2-x1);i++){
    		printf("L");
		}
		printf("L");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("D");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("R");
		}
	    printf("U");
	    printf("R");
	    for(int i=1;i<=(y2-y1)+1;i++){
	    	printf("U");
		}
	    for(int i=1;i<=(x2-x1)+1;i++){
	    	printf("L");
		}
	    printf("D");
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
  ^