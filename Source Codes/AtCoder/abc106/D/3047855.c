int t[500][500];
main(){
  int N,M,Q;
  scanf("%d%d%d",&N,&M,&Q);
  for(int i=M;i--;){
    int l,r;
    scanf("%d%d",&l,&r);
    l--;r--;
    t[l][r]++;
  }
  for(int i=500;i--;)for(int j=0;j<499;j++)t[i][j+1]+=t[i][j];
  for(int i=499;i--;)for(int j=0;j<500;j++)t[i][j]+=t[i+1][j];
  for(int i=Q;i--;){
    int p,q;
    scanf("%d%d",&p,&q);
    p--;q--;
    printf("%d\n",t[p][q]);
  }
} ./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d",&N,&M,&Q);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:17:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n",t[p][q]);
     ^
./Main.c:17:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:17:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’