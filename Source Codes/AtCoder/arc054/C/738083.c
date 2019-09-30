#include<stdio.h>

int main(i,j,k,l,n,tmp){
	int a[201][201],c = 1;
	char s[10][10] = {"Even","Odd"};
	char ss[201];
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%s",ss);
		for(j = 0;j < n;j++){
			a[i][j] = ss[j] - '0';
		}
	}
	for(i = 0;i < n;i++){
		for(k = i;1/*a[k][i] == 0*/;k++){
			if(k == n){
				c = 0;
				break;
			}
			if(a[k][i] != 0)break;
		}
		if(!c)break;
		
		for(j = k+1;j < n;j++){
			if(a[j][i] == 1){
				for(l = 0;l < n;l++){
					a[j][l] ^= a[k][l];
				}
			}
		}
		for(j = 0;j < n;j++){
			tmp = a[i][j];
			a[i][j] = a[k][j];
			a[k][j] = tmp;
		}
	}
	printf("%s\n",s[c]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:3:5: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
 int main(i,j,k,l,n,tmp){
     ^
./Main.c:3:5: warning: type of ‘j’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:5: warning: type of ‘k’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:5: warning: type of ‘l’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:5: warning: type of ‘tmp’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",ss);
   ^