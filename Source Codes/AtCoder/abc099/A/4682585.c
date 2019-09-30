main()
{
  int n;
  scanf("%d",&n);
  if(n<=999)
    printf("ABC");
  else
    printf("ABD");
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d",&n);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:6:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("ABC");
     ^
./Main.c:6:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:6:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:8:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("ABD");
     ^
./Main.c:8:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’