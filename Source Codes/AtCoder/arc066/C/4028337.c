long a,b,c;o;main(A){b=c=-1e18;for(scanf("%*d");~scanf("%c%d ",&o,&A);)b=o%3?a+=A,fmax(b-A,c+=A):(a=fmax(a-A,c=b+A));printf("%ld",a);} ./Main.c:1:12: warning: data definition has no type or storage class
 long a,b,c;o;main(A){b=c=-1e18;for(scanf("%*d");~scanf("%c%d ",&o,&A);)b=o%3?a+=A,fmax(b-A,c+=A):(a=fmax(a-A,c=b+A));printf("%ld",a);}
            ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘o’ [-Wimplicit-int]
./Main.c:1:14: warning: return type defaults to ‘int’ [-Wimplicit-int]
 long a,b,c;o;main(A){b=c=-1e18;for(scanf("%*d");~scanf("%c%d ",&o,&A);)b=o%3?a+=A,fmax(b-A,c+=A):(a=fmax(a-A,c=b+A));printf("%ld",a);}
              ^
./Main.c: In function ‘main’:
./Main.c:1:14: warning: type of ‘A’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:36: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 long a,b,c;o;main(A){b=c=-1e18;for(scanf("%*d");~scanf("%c%d ",&o,&A);)b=o%3?a+=A,fmax(b-A,c+=A):(a=fmax(a-A,c=b+A));printf("%ld",a);}
                                    ^
./Main.c:1:36: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:1:36: note: include ‘<stdi...