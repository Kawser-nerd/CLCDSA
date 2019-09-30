long long i,j,e,t,w,u,x[1<<17],y[1<<17];
int main(n){
  scanf("%d%lld%lld",&n,&e,&t);
  for(x[n]=2*e;i<n;){
    scanf("%lld",&x[i]);
    x[i++]*=2;
  }
  for(i=0,w=1ll<<50;i<n;){
    for(;j<i&&t<x[i]-x[j];){
      u=y[j]+x[i]-x[j++];
      w=w<u?w:u;
    }
    u=x[i]-x[j];
    u=y[j]+(u<t?t:u);
    y[i+1]=w<u?w:u;
    w+=(x[i+1]-x[i++]);
  }
  printf("%lld\n",y[n]+e);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:2:5: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 int main(n){
     ^
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%lld%lld",&n,&e,&t);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:18:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%lld\n",y[n]+e);
   ^
./Main.c:18:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:18:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’