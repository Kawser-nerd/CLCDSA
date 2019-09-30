int compare_int(const void *a, const void *b){
    return *(int*)b - *(int*)a;
}

int n, m, x[100000], ans, sum, i;
int main(){
  scanf("%d%d", &n, &m);
  if(n>=m){
    puts("0");
    return 0;
  }
  for(i=0; i<m; i++){
    scanf("%d", x+i);
  }
  qsort(x, m, sizeof(int), compare_int);
  sum=x[0]-x[m-1];
  for(i=0; i<m-1; i++){
    x[i]=x[i]-x[i+1];
  }
  qsort(x, m-1, sizeof(int), compare_int);
  for(i=0; i<n-1; i++){
    ans+=x[i];
  }
  printf("%d\n", sum-ans);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d", &n, &m);
   ^
./Main.c:7:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:7:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:9:5: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
     puts("0");
     ^
./Main.c:15:3: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
   qsort(x, m, sizeof(int), compare_int);
   ^
./Main.c:24:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n", sum-ans);
   ^
./Main.c:24:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:24:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’