int dif(int a, int b){return a<b?b-a:a-b;}
int gcd(int a, int b){
  int r = a % b;
  while(r!=0){
    a = b;
    b = r;
    r = a % b;
  }
  return b;
}

int n, X, x, ans, i;
int main(){
  scanf("%d%d", &n, &X);
  scanf("%d", &x);
  ans = dif(x,X);
  for(i=1; i<n; i++){
    scanf("%d", &x);
    ans = gcd(ans, dif(x,X));
  }
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &n, &X);
   ^
./Main.c:14:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:14:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:21:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", ans);
   ^
./Main.c:21:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:21:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’