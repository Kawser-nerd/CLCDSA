#include <stdio.h>
#include <stdlib.h>

int compare (const void *x, const void *y);

int main(){
  unsigned long long int ans;
  int p;
  int cases,ccases;
  int l;
  int k;
  int freq[1010];
  int i,j,m;

  scanf(" %d ", &cases);

  for(ccases=1; ccases<=cases; ccases++){
    ans=0;
    scanf(" %d %d %d ",&p,&k,&l);
    for(i=0;i<l;i++)
      scanf(" %d ",&freq[i]);

    qsort(freq,l,sizeof(int),compare);

/*     for(i=0;i<l;i++) */
/*       printf(" %d ",freq[i]); */
/*     printf("\n"); */

    j=1;
    m=1;
    for(i=0;i<l;i++){
      ans+=freq[i]*m;
      if(j==k){
	m++;
	j=0;
      }
      j++;
    }
    printf("Case #%d: %llu\n",ccases,ans);
  }

  return 0;
}


int compare (const void *x, const void *y){
  return *(int *)y-*(int *)x;
}
