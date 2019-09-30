#include <stdio.h>

main()
{
	int j,N,m,n,i,dump;
	scanf ("%d",&N);
	int S[N],E[N],count[482];
	i=0;
	for (n=0;n!=N;n++){
		scanf("%d",&S[n]);
		dump=getchar();
		scanf("%d",&E[n]);
		if ((S[n]%10)!=0){
			if ((S[n]%10)<5){
				S[n]=S[n]/10*10;
			}else{
				S[n]=S[n]/10*10+5;
			}
		}
		if ((E[n]%10)!=0){
			if ((E[n]%10)<=5){
				E[n]=E[n]/10*10+5;
			}else{
				E[n]=E[n]/10*10+10;
			}
		}
	}

	
	n=0;
	do {
		count[n]=0;
		n++;
	}while(n!=482);

	for (n=0;n!=N;n++){
		count[S[n]/5]++;
		count[(E[n]/5)]--;
	}

	m=0;
	i=0;

	m+=count[0];
	if (count[0]!=0){
		S[i]=0;
	}
	for (n=1;n!=482;n++){
		m+=count[n];
		count[n]=m;
		
	}

	for (n=0;n!=24;n++){
		if (count[12+(n*20)-1]>0){
			for (j=1;j!=9;j++){
				count[12+(n*20)+j-1]=count[12+(n*20)-1];
			}
		}
	}


	for (n=1;n!=482;n++){
		if (count[n-1]==0 && count[n]!=0){
			S[i]=n;
		}
		if (count[n-1]!=0 && count[n]==0){
				E[i]=n;
			i++;
		}
	}

	for (n=0;n!=(i);n++){
		printf ("%04d-%04d\n",S[n]*5,E[n]*5);
	}
	
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf ("%d",&N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&S[n]);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&E[n]);
   ^