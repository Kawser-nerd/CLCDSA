#include <stdio.h>
#include <math.h>

int main(void)
{
int n,i,j;
int x[101];
int y[101];
double max = 0;

scanf("%d", &n);
for(i = 0; i < n; i++){
scanf("%d %d", &x[i], &y[i]);
}

for (i = 0; i < n; i++){
for (j = 0; j < n; j++){
if (max < sqrt(pow(x[j]-x[i], 2)+pow(y[j]-y[i], 2))){
max = sqrt(pow(x[j]-x[i], 2)+pow(y[j]-y[i], 2));
}
}
}

printf("%lf", max);

return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d", &n);
 ^
./Main.c:13:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d %d", &x[i], &y[i]);
 ^