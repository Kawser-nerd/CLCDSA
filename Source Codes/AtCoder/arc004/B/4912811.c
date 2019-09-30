i;S;M;main(d){for(;~scanf("%d",&d);)i?M=d>M?d:M,S+=d:i++;printf("%d %.f\n",S,fmax(0,2*M-S));} ./Main.c:1:1: warning: data definition has no type or storage class
 i;S;M;main(d){for(;~scanf("%d",&d);)i?M=d>M?d:M,S+=d:i++;printf("%d %.f\n",S,fmax(0,2*M-S));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 i;S;M;main(d){for(;~scanf("%d",&d);)i?M=d>M?d:M,S+=d:i++;printf("%d %.f\n",S,fmax(0,2*M-S));}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘S’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 i;S;M;main(d){for(;~scanf("%d",&d);)i?M=d>M?d:M,S+=d:i++;printf("%d %.f\n",S,fmax(0,2*M-S));}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:7: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i;S;M;main(d){for(;~scanf("%d",&d);)i?M=d>M?d:M,S+=d:i++;printf("%d %.f\n",S,fmax(0,2*M-S));}
       ^
./Main.c: In function ‘main’:
./Main.c:1:7: warning: type of ‘d’ defaults to ‘int’ [-Wimpli...