#include <stdio.h>
#include <stdlib.h>
int main(void){
	
	int testcase;
	int smax=0;
	int *people;
	int tmp;
	int num=0, i=0;
	int total=0;
	char a;
	scanf("%d", &testcase);

	
	
	for(tmp=1;tmp<=testcase;tmp++){
		num=0;
		total=0;
		scanf("%d", &smax);
		people=(int*)malloc(sizeof(int)*(smax+1));
		a=getc(stdin);
		for(i=0;i<smax+1;i++){
			a=getc(stdin);
			*(people+i)=a-48;
		}

		for(i=0;i<smax+1;i++){
			if(total<i){
				num+=i-total;
				total+=i-total;
			}
			total+=*(people+i);
		}

		printf("Case #%d: %d\n", tmp, num);
		free(people);
		
	}
	return 0;
}
