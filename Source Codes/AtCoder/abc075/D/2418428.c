#include<stdio.h>

long long int min(long long int x,long long int y){
  if(x<y) return x;
  else return y;
}

long long int max(long long int x,long long int y){
  if(x>y) return x;
  else return y;
}

int main(){
  int n,k,i,j,l,m,o,cnt=0;
  long long int x[50],y[50],xmin,xmax,ymin,ymax,s;
  s=4000000000000000000;
  scanf("%d %d",&n,&k);
  for(i=0;i<n;i++){
    scanf("%ld %ld",&x[i],&y[i]);
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i!=j){
        xmin=min(x[i],x[j]);
        xmax=max(x[i],x[j]);
        for(l=0;l<n;l++){
          for(m=0;m<n;m++){
            if(l!=m){
              cnt=0;
              ymin=min(y[l],y[m]);
              ymax=max(y[l],y[m]);
              for(o=0;o<n;o++){
                if(x[o]>=xmin&&x[o]<=xmax&&y[o]<=ymax&&y[o]>=ymin)
                  cnt++;
              }
              if(cnt>=k) s=min(s,(xmax-xmin)*(ymax-ymin));
            }
          }
        }
      }
    }
  }
  printf("%ld\n",s);
} ./Main.c: In function ‘main’:
./Main.c:19:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 2 has type ‘long long int *’ [-Wformat=]
     scanf("%ld %ld",&x[i],&y[i]);
           ^
./Main.c:19:11: warning: format ‘%ld’ expects argument of type ‘long int *’, but argument 3 has type ‘long long int *’ [-Wformat=]
./Main.c:43:10: warning: format ‘%ld’ expects argument of type ‘long int’, but argument 2 has type ‘long long int’ [-Wformat=]
   printf("%ld\n",s);
          ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&k);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld",&x[i],&y[i]);
     ^