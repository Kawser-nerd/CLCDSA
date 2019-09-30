#include <stdlib.h>
#include <stdio.h>

#define F0(i,n) for(int i=0;i<n;i++)

int main(){
        int T;
	char *N = malloc(20*sizeof(char));
	int l=0;
        scanf("%d\n",&T);
        F0(i,T){
		printf("Case #%d: ",i+1);
                scanf("%s\n",N);
        	l=0;
		while(N[l] != '\0')l++;
		char prev = '\0';
		int index = -1;
		int s = 0;
		F0(j,l){
			if(prev < N[j]){index = j;s=1;prev = N[j];}
			else if(prev == N[j]){s++;}
			else{break;}
		}
		if(index + s == l){
			// we have nothing to do
			printf("%s",N);
		}else if(index == 0 && N[index] == '1'){
			// output l-1 '9's
			F0(k,l-1)printf("%c",'9');
		}else{
			// output from 0 to index -1 the originals
			F0(k,index)printf("%c",N[k]);
			printf("%c",N[index]-1);
			// output l-index '9's
			F0(k,l-index-1)printf("%c",'9');
		}
		printf("\n");
	}
}
