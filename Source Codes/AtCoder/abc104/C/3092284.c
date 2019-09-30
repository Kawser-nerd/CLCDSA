#include<stdio.h>

int main(){
		int d,g;
		scanf("%d%d",&d,&g);
		int p[d][2],i,j,test[10],temp=0,point=0,mini=0;
		for(i=0;i<d;i++){
				scanf("%d%d",&p[i][0],&p[i][1]);
				mini+=p[i][0];
		}
		for(test[0]=0;test[0]<2;test[0]++){
		for(test[1]=0;test[1]<2;test[1]++){
		for(test[2]=0;test[2]<2;test[2]++){
		for(test[3]=0;test[3]<2;test[3]++){
		for(test[4]=0;test[4]<2;test[4]++){
		for(test[5]=0;test[5]<2;test[5]++){
		for(test[6]=0;test[6]<2;test[6]++){
		for(test[7]=0;test[7]<2;test[7]++){
		for(test[8]=0;test[8]<2;test[8]++){
		for(test[9]=0;test[9]<2;test[9]++){
				temp=0;point=0;i=0;
				while(i<d){
						if(test[i]==1){
								temp+=p[i][0];
								point+=p[i][1];
								point+=(p[i][0]*(i+1)*100);
						}
						i++;
				}i=d-1;
				while(g>point){
					if(test[i]==0){
							for(j=0;j<p[i][0];j++){
									point+=(i+1)*100;
									temp++;
									if(g<=point)break;
							}
							if(j==p[i][0]-1)point+=p[i][1];
					}
					i--;
				}
				if(temp<mini)mini=temp;
		}
		}
		}
		}
		}
		}
		}
		}
		}
		}
		printf("%d\n",mini);
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&d,&g);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",&p[i][0],&p[i][1]);
     ^