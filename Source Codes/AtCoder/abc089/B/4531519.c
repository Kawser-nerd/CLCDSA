char *S[] = {"Three","Four"};
char f;
int n, i;
char c;
int main(){
  scanf("%d\n", &n);
  for(i=0; i<n; i++){
    scanf("%c", &c);
    if(c=='Y') f=1;
  }
  puts(S[f]);
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d\n", &n);
   ^
./Main.c:6:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:6:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:11:3: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
   puts(S[f]);
   ^