#include <stdio.h>
#include <stdlib.h>

int answers[501];

int main() {

  int T, i, n, j, temp[26], k;

  scanf("%d", &T);

  for(i=2; i<=25; i++) {
    for(j=0; j<(1<<(i-2)); j++) {
      k=j;
      for(n=2; n<i; n++) {
	temp[n]=k%2;
	k/=2;
      }
      temp[i]=1;
      k=1;
      for(n=2; n<=i; n++)
	if(temp[n]) {
	  temp[n]=k;
	  k++;
	}
      k=i;
      int l=temp[k];
      while(l!=1) {
	k=l;
	l=temp[k];
	if(l==0)
	  break;
      }
      if(l==1) answers[i]++;
    }

    //printf("%d: %d\n", i, answers[i]);
  }  
  
  for(i=0; i<T; i++) {
    scanf("%d", &n);
    printf("Case #%d: %d\n", (i+1), answers[n]%100003);
  }

  return 0;
    
}
