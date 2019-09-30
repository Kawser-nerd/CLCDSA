p(n,i){if(n<2)return 1;for(i=2;i<n;)if(n%i++==0)return 1;return 0;}main(n){scanf("%d",&n);puts(p(n*(n+1)/2)==0?"WANWAN":"BOWWOW");} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 p(n,i){if(n<2)return 1;for(i=2;i<n;)if(n%i++==0)return 1;return 0;}main(n){scanf("%d",&n);puts(p(n*(n+1)/2)==0?"WANWAN":"BOWWOW");}
 ^
./Main.c: In function ‘p’:
./Main.c:1:1: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘i’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: At top level:
./Main.c:1:68: warning: return type defaults to ‘int’ [-Wimplicit-int]
 p(n,i){if(n<2)return 1;for(i=2;i<n;)if(n%i++==0)return 1;return 0;}main(n){scanf("%d",&n);puts(p(n*(n+1)/2)==0?"WANWAN":"BOWWOW");}
                                                                    ^
./Main.c: In function ‘main’:
./Main.c:1:68: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:76: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
 p(n,i){if(n<2)return 1;for(i=2;i<n;)if(n%i++==0)return 1;return 0;}main(n){scanf("%d",&n);puts(p(n*(n+1)/2)==0?"WANWAN":"BOWWOW");}
                    ...