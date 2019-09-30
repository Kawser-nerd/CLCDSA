long long int n, i;
char S[101];
int main(){
  scanf("%s%lld", S, &n);
  n--;
  for(i=0; i<n; i++){
    if(S[i]!='1') break;
  }
  printf("%c\n", S[i]);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%s%lld", S, &n);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:9:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%c\n", S[i]);
   ^
./Main.c:9:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:9:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’