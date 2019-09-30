#include<stdio.h>
#include<stdlib.h>

#define max(a,b) ((a)>(b)?(a):(b))

int main(){
		int n,i,j,k,h;
		long xyz[100][3],ans[3],highest=0;
		scanf("%d",&n);
		for(i=0;i<n;i++){
				scanf("%ld%ld%ld",&xyz[i][0],&xyz[i][1],&xyz[i][2]);
				highest=max(highest,xyz[i][2]);
		}
		for(k=highest;;k++){
				for(i=0;i<=100;i++){
						for(j=0;j<=100;j++){
						int f=0;
								for(h=0;h<n;h++){
										if(xyz[h][2]!=max(k-abs(xyz[h][0]-i)-abs(xyz[h][1]-j),0)){
												f=1;
												break;
										}
								}
								if(f==0){
										printf("%ld %ld %ld\n",i,j,k);
										return 0;
								}
						}
				}
		}
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:25:18: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘int’ [-Wformat=]
           printf("%ld %ld %ld\n",i,j,k);
                  ^
./Main.c:25:18: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 3 has type ‘int’ [-Wformat=]
./Main.c:25:18: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 4 has type ‘int’ [-Wformat=]
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld%ld%ld",&xyz[i][0],&xyz[i][1],&xyz[i][2]);
     ^