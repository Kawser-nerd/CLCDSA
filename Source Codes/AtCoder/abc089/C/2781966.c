#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
 
/*????????
int sort(const void *a, const void *b){
    return *(int*)a-*(int*)b ;
}
    qsort (data,sizeof(data),sizeof(int),sort); 
*/
 
int main(void){
    long long n,m=0,a=0,r=0,c=0,h=0;
    scanf("%lld",&n);
    char s[n][12];
    for (int i=0; i<n; i++){
        scanf("%s",s[i]);
        if (s[i][0]=='M'){
            m++;
        } else if (s[i][0]=='A'){
            a++;
        } else if (s[i][0]=='R'){
            r++;
        } else if (s[i][0]=='C'){
            c++;
        } else if (s[i][0]=='H'){
            h++;
        }
    }
    long long ans;
    ans = m*a*r + m*a*c + m*a*h + m*r*c + m*r*h + m*c*h + a*r*c +a*r*h + a*c*h +r*c*h ;
    printf ("%lld\n",ans);
	return 0 ;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lld",&n);
     ^
./Main.c:18:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s",s[i]);
         ^