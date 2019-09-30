#include <stdio.h>

double w[1005];
double p[1005];
int used[1005];

int main(){


	int N,K;

	scanf("%d %d",&N,&K);


	int i;//14:23

	for(i=0;i<N;i++){
		scanf("%lf %lf",&w[i],&p[i]);
	}

	double water=0;
	double salt=0;

	while(1){

		if(K==0){break;}

		int idx;
		double max=-114514.0;
		for(i=0;i<N;i++){
			if(used[i]==0){
				double add=w[i]*p[i]/100.0;
				double water2=water+w[i]-add;
				double salt2=salt+add;
				double per;
				if(salt2==0){per=0;}
				else{per=salt2/(water2+salt2);}
				if(max<per){
					max=per;
					idx=i;
				}
			}
		}
		double add2=w[idx]*p[idx]/100.0;
		water+=w[idx]-add2;
		salt+=add2;
		used[idx]=1;
		K--;
	}

	if(salt==0){printf("%.10f\n",0);}
	else{printf("%.10f\n",salt*100.0/(water+salt));}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:51:21: warning: format ‘%f’ expects argument of type ‘double’, but argument 2 has type ‘int’ [-Wformat=]
  if(salt==0){printf("%.10f\n",0);}
                     ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf %lf",&w[i],&p[i]);
   ^