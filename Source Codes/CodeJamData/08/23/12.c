#include <stdio.h>

int main(){
  int c[1000000],w[1000000],n,Z,z,ind[100],K,i,p,v,m;
  scanf("%d",&Z);
  for(z=0;z<Z;z++){
    scanf("%d %d", &K,&n);
    for(i=0;i<n;i++) scanf("%d", &ind[i]);
    for(i=0;i<K;i++) {
      c[i]=0;
      w[i]=i;
    }
    p=-1;
    for(v=1;v<=K;v++){
      m=K+1-v;
      p=(p+v)%m;
      c[w[p]]=v;
      for(i=p;i<m;i++) w[i]=w[i+1];
      p--;
    }
    
    printf("Case #%d: ", z+1);
    for(i=0;i<n;i++) printf("%d ", c[ind[i]-1]);
    printf("\n");
  }
  return 0;
}
