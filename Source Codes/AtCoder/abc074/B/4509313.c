int def2(int a, int b){return a<b?b-a:a-b;}
int min2(int a, int b){return a>b?b:a;}
int n, k, x, ans, now, i;
int main(){
  scanf("%d%d", &n, &k);
  for(i=0; i<n; i++){
    scanf("%d", &x);
    now=min2(def2(0,x),def2(k,x))<<1;
    ans+=now;
  }
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &n, &k);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:11:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", ans);
   ^
./Main.c:11:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:11:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’