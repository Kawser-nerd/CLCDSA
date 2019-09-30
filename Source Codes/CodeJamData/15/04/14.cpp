#include <cstdio>
int t,x,r,c;
int main(){
	scanf("%d",&t);
	for(int y=1;y<=t;y++){
		scanf("%d %d %d",&x,&r,&c);
		if(x>=7||r*c%x!=0){
			printf("Case #%d: RICHARD\n",y);
		}
		else if(x<=2){
			printf("Case #%d: GABRIEL\n",y);
		}
		else if(x==3){
			if(r<=1||c<=1){
				printf("Case #%d: RICHARD\n",y);
			}
			else{
				printf("Case #%d: GABRIEL\n",y);
			}
		}
		else if(x==4){
			if(r<=2||c<=2){	
				printf("Case #%d: RICHARD\n",y);
			}
			else{
				printf("Case #%d: GABRIEL\n",y);
			}
		}
		else if(x==5){
			if(r<=2||c<=2||r==3&&c==5||r==5&&c==3){
				printf("Case #%d: RICHARD\n",y);
			}
			else{
				printf("Case #%d: GABRIEL\n",y);
			}
		}
		else if(x==6){
			if(r<=3||c<=3){	
				printf("Case #%d: RICHARD\n",y);
			}
			else{
				printf("Case #%d: GABRIEL\n",y);
			}
		}
	}		
	return 0;
}
