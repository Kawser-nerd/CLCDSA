main()
{
  int a,b,c,d,e,f;
  scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
  printf("%d\n",(a*b+c*d+e*f)/10);
  return 0;
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:5:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%d\n",(a*b+c*d+e*f)/10);
   ^
./Main.c:5:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:5:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’