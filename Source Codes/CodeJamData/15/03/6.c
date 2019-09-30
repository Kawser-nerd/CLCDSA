#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void){
	
	int testcase;
	int tmp=1;
	int l=0;
	long long int x;
	int i;
	char a;
	int s[8][3]={3, 5, 7,
				 4, 6, 8,
				 2, 7, 6,
				 1, 8, 5,
				 8, 2, 3,
				 7, 1, 4,
				 5, 4, 2,
				 6, 3, 1};
	int *str;
	int compare_with=0;
	int cur=0, next=0;
	int counter=0;
	scanf("%d", &testcase);
	
	for(tmp=1;tmp<=testcase;tmp++){

		cur=0;
		counter=0;
		scanf("%d", &l);
		scanf("%lld", &x);

		if(x>12){
			x=12+x%4;
		}

		str=(int*)malloc(sizeof(int)*l);
		getc(stdin);
		for(i=0;i<l;i++){
			a=getc(stdin);
			switch(a){
				case 105 : *(str+i)=0; break;
				case 106 : *(str+i)=1; break;
				case 107 : *(str+i)=2; break;
				default : ;
			}
		}
		cur=1;
		compare_with=3;

		for(i=0;i<x*l;i++){

			next=*(str+i%l);
			cur=s[cur-1][next];
			if(cur==compare_with){
				compare_with+=2;
				cur=1;
				counter++;
			}
			if(compare_with==7) break;
		}
		i++;
		for(;i<x*l;i++){
			next=*(str+i%l);
			cur=s[cur-1][next];
		}
		if(cur==compare_with) counter++;
		if(counter==3)
			printf("Case #%d: YES\n", tmp);
		else printf("Case #%d: NO\n", tmp);

		free(str);
	}
	return 0;
}
