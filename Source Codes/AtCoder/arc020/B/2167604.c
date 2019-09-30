#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int n,c;
	int *a;
	scanf("%d %d",&n,&c);
	int even[10] = {} ,odd[10] = {};
	int e_c=0,o_c=0;
	int se_c=-1,so_c=-1;
	int e_n,o_n;
	o_n = n/2;
	e_n = o_n + (n%2);
	a = malloc(n*sizeof(int));
	for(int i = 0;i<n;i++){
		scanf("%d",a+i);
		if(i%2)odd[a[i]-1]++;
		else even[a[i]-1]++;
	}

	for(int i = 1; i < 10; i ++){
		if(odd[o_c] <= odd[i]) {
			so_c = o_c;
			o_c = i;
		}
		if(even[e_c] <= even[i]){
			 se_c = e_c;
			 e_c = i;
		}
	}
	int change = 0;

	if(e_c == o_c){
		if(se_c == -1 && so_c == -1){
			change = n / 2;

		}else if(so_c == -1){

			change = n - odd[o_c] - even[se_c];

		}else if(se_c == -1){

			change = n - even[e_c] - odd[o_c];
		}else{
			if(even[e_c] + odd[so_c] > even[se_c] + odd[o_c] )
			{
				change = n - even[e_c] - odd[so_c];
			}else {
				change = n - even[se_c] - odd[o_c] ;
			}

		}

	}else{
		change = n - even[e_c]- odd[o_c];
	}


	printf("%d\n",change * c);



	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&n,&c);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",a+i);
   ^