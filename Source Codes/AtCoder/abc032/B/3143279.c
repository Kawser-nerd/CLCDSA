char s[333];c,i,j,f,l;
main(n){
	scanf("%s%d",s,&n);
	l=strlen(s);
	for(;i+n<=l;i++)
	{
		for(f=0,j=i+1;j+n<=l;j++)f+=!strncmp(s+i,s+j,n);
		c+=!f;
	}
	printf("%d\n",c);
} ./Main.c:1:13: warning: data definition has no type or storage class
 char s[333];c,i,j,f,l;
             ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 char s[333];c,i,j,f,l;
               ^
./Main.c:1:17: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 char s[333];c,i,j,f,l;
                 ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 char s[333];c,i,j,f,l;
                   ^
./Main.c:1:21: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 char s[333];c,i,j,f,l;
                     ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(n){
 ^
./Main.c: In function ‘main’:
./Main.c:2:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:3:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%s%d",s,&n);
...