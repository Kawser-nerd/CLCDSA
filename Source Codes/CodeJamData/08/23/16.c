#include <stdio.h>


int main(){
  int t, i, j, x, cont;
  int k, n, vn[1000001];
  scanf("%d", &t);
  for(i=0;i<t;i++){

    for(j=0;j<1000001;j++){
      vn[j]=0;
    }

    scanf("%d %d", &k, &n);
    
    x=0;
    for(j=1;j<=k;j++){
      cont=0;
      while(cont<j){
	x++;
	if(x==(k+1)) x=1;
	if(vn[x]==0){
	  cont++;
	}
      }
      vn[x]=j;
    }
    
    printf("Case #%d: ", i+1);
    for(j=0;j<n;j++){
      scanf("%d", &x);
      printf("%d ", vn[x]);
    }
    printf("\n");
  }
  return 0;
}
