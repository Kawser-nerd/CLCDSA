int n, k, ans, i;
int main(){
  scanf("%d%d", &n, &k);
  ans=1;
  for(i=0; i<n; i++){
    if(ans>=k){
      break;
    }else{
      ans<<=1;
    }
  }
  for(; i<n; i++){
    ans+=k;
  }
  printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &n, &k);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:15:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", ans);
   ^
./Main.c:15:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:15:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’