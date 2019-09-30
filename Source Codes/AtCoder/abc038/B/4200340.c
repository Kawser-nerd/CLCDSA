int main(void){
  int a,b,c,d;
  scanf("%d%d%d%d",&a,&b,&c,&d);
  int check1,check2,check3,check4;
  check1 = a-c;
  check2 = a-d;
  check3 = b-c;
  check4 = b-d;
  if(check1*check2*check3*check4)
  {
	puts("NO");
  }
  else
  {
    puts("YES");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:3:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d%d",&a,&b,&c,&d);
   ^
./Main.c:3:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:3:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:11:2: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
  puts("NO");
  ^