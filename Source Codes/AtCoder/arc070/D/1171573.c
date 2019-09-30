z[9999],r[9999],x,a,b,c,h;
f(a,b){
	fflush(!printf("? %d %d\n",a,b));
	scanf("%s",&x);
	return x=='Y';
}
main(i){
	if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return 0;}
	for(i=a+=b;~--i;)!c||f(i,z[c-1])?(z[c++]=i):c--;
	for(h=*z,i=a;~--i;)r[i]=f(h,i);
	for(printf("! "),i=0;i<a;)printf("%d",r[i++]);
	puts("");
} ./Main.c:1:1: warning: data definition has no type or storage class
 z[9999],r[9999],x,a,b,c,h;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘z’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘r’ [-Wimplicit-int]
 z[9999],r[9999],x,a,b,c,h;
         ^
./Main.c:1:17: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
 z[9999],r[9999],x,a,b,c,h;
                 ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 z[9999],r[9999],x,a,b,c,h;
                   ^
./Main.c:1:21: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 z[9999],r[9999],x,a,b,c,h;
                     ^
./Main.c:1:23: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 z[9999],r[9999],x,a,b,c,h;
                       ^
./Main.c:1:25: warning: type defaults to ‘int’ in declaration of ‘h’ [-Wimplicit-int]
 z[9999],r[9999],x,a,b,c,h;
                         ^
./Main.c:2:1: warning: r...