int main()
 {
  int x,y,z;
   scanf("%d %d",&x,&y);
   z=y/x;
    printf("%d\n",z);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:4: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
    scanf("%d %d",&x,&y);
    ^
./Main.c:4:4: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:4: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n",z);
     ^
./Main.c:6:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’