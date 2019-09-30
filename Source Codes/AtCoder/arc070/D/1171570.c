int z[9999],r[9999],x;
int f(int a,int b){
	fflush(!printf("? %d %d\n",a,b));
	scanf("%s",&x);
	return x=='Y';
}
int main(){
	int a,b,c=0,h,i;
	if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return 0;}
	for(i=a+=b;~--i;)!c||f(i,z[c-1])?(z[c++]=i):c--;
	for(h=*z,i=a;~--i;)r[i]=f(h,i);
	for(printf("! "),i=0;i<a;)printf("%d",r[i++]);
	puts("");
} ./Main.c: In function ‘f’:
./Main.c:3:2: warning: implicit declaration of function ‘fflush’ [-Wimplicit-function-declaration]
  fflush(!printf("? %d %d\n",a,b));
  ^
./Main.c:3:10: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  fflush(!printf("? %d %d\n",a,b));
          ^
./Main.c:3:10: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:3:10: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:4:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%s",&x);
  ^
./Main.c:4:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:4:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
  scanf("%s",&x);
        ^
./Main.c: In function ‘main’:
./Main.c:9:5: warning: incompatible implicit declaration of built-in function ‘scanf’
...