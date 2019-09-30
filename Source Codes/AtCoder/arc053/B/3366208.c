c[26],cnt;char s[1<<17];n,i;
main(){
	read(0,s,100100);
	n=strlen(s)-1;
	for(;i<n;i++)c[s[i]-97]++;
	for(i=0;i<26;i++)cnt+=c[i]&1;
	printf("%d\n",cnt?(n-cnt)/cnt/2*2+1:n);
} ./Main.c:1:1: warning: data definition has no type or storage class
 c[26],cnt;char s[1<<17];n,i;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:7: warning: type defaults to ‘int’ in declaration of ‘cnt’ [-Wimplicit-int]
 c[26],cnt;char s[1<<17];n,i;
       ^
./Main.c:1:25: warning: data definition has no type or storage class
 c[26],cnt;char s[1<<17];n,i;
                         ^
./Main.c:1:25: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:27: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 c[26],cnt;char s[1<<17];n,i;
                           ^
./Main.c:2:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:3:2: warning: implicit declaration of function ‘read’ [-Wimplicit-function-declaration]
  read(0,s,100100);
  ^
./Main.c:4:4: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
  n=strlen(s)-1;...