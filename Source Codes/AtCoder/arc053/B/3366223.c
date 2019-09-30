c[26],cnt;s;n,i;
main(){
	for(;(s=getchar_unlocked()-97)>=0;n++)c[s]++;
	for(;i<26;i++)cnt+=c[i]&1;
	printf("%d\n",cnt?(n-cnt)/cnt|1:n);
} ./Main.c:1:1: warning: data definition has no type or storage class
 c[26],cnt;s;n,i;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘cnt’ [-Wimplicit-int]
 c[26],cnt;s;n,i;
       ^
./Main.c:1:11: warning: data definition has no type or storage class
 c[26],cnt;s;n,i;
           ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:13: warning: data definition has no type or storage class
 c[26],cnt;s;n,i;
             ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:15: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 c[26],cnt;s;n,i;
               ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:10: warning: implicit declaration of function ‘getchar_unlocked’ [-Wimplicit-function-declaration]
  for(;(s=get...