#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int compare_int(const void *a, const void *b){
    return *(int*)a - *(int*)b;
}

int main(void){
	int n;
	scanf("%d", &n);
	char s_e[n][10];
	int se[n];
	char ans[n][10];
	for(int i=0; i<n; i++){
		scanf("%s", s_e[i]);
	}
	for(int j=0; j<n; j++){
		se[j] = 0;
		for(int k=0; k<4; k++){
			se[j] += ((s_e[j][k]-'0')*pow(10, 7-k) + (s_e[j][k+5]-'0')*pow(10, 3-k));
		}
	}
	qsort(se, n, sizeof(int), compare_int);
	for(int p=0; p<n; p++){
		if((se[p]/10000)%10 != 0){
			se[p] -= ((se[p]/10000)%5)*10000;
		}
		if((se[p])%5 != 0){
			se[p] += (5-(se[p])%5);
			if((se[p]-(se[p]/100)*100)%60 == 0){
				se[p] +=40;
			}
		}
	}
	for(int q=0; q<n; q++){
		if((q!=n-1) && ((se[q]%10000)>=(se[q+1]/10000))){
			if((se[q]%10000)<(se[q+1]%10000)){
				se[q+1] = se[q] - (se[q]%10000) + (se[q+1]%10000);
			}
			else{
				se[q+1] = se[q];
			}
			for(int r=0; r<9; r++){
				ans[q][r] = 'N';
			}
			ans[q][9] = '\0';
		}
		else{
			for(int s=0; s<4; s++){
				ans[q][s] = ((int)(se[q])%(int)(pow(10, 8-s)) - (int)(se[q])%(int)(pow(10, 7-s)))/(int)(pow(10, 7-s)) + '0';
				ans[q][s+5] = ((int)(se[q])%(int)(pow(10, 4-s)) - (int)(se[q])%(int)(pow(10, 3-s)))/(int)(pow(10, 3-s)) + '0';
			}
			ans[q][4] = '-';
			ans[q][9] = '\0';
		}
	}
	for(int x=0; x<n; x++){
		if(ans[x][0] != 'N'){
			for(int y=0; y<9; y++){
				printf("%c", ans[x][y]);
			}
			printf("\n");
		}
	}
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &n);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s_e[i]);
   ^