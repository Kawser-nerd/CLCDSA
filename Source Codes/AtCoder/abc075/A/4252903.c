main()
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  if(a==b)
  {
    printf("%d\n",c);
  }
  else if(a==c)
  {
    printf("%d\n",b);
  }
  else
  {
	printf("%d\n",a);
  }
  return 0;
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main()
 ^
./Main.c: In function ‘main’:
./Main.c:4:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d",&a,&b,&c);
   ^
./Main.c:4:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:7:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n",c);
     ^
./Main.c:7:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:7:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:11:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("%d\n",b);
     ^
./Main.c:11:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:15:2: warning: incompatible implicit declaration of built-in function ‘printf’
  printf("%d\n",a);
  ^
./Main.c:15:2...