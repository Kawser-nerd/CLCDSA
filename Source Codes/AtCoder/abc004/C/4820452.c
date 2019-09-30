c[]={1,2,3,4,5,6};i;j;main(n){for(scanf("%d",&n),n%=30;i<n;)c[i++%5+1]^=c[i%5]^=c[i%5+1]^=c[i%5];for(;j<6;)putchar(48+c[j++]);puts("");} ./Main.c:1:1: warning: data definition has no type or storage class
 c[]={1,2,3,4,5,6};i;j;main(n){for(scanf("%d",&n),n%=30;i<n;)c[i++%5+1]^=c[i%5]^=c[i%5+1]^=c[i%5];for(;j<6;)putchar(48+c[j++]);puts("");}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:19: warning: data definition has no type or storage class
 c[]={1,2,3,4,5,6};i;j;main(n){for(scanf("%d",&n),n%=30;i<n;)c[i++%5+1]^=c[i%5]^=c[i%5+1]^=c[i%5];for(;j<6;)putchar(48+c[j++]);puts("");}
                   ^
./Main.c:1:19: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:21: warning: data definition has no type or storage class
 c[]={1,2,3,4,5,6};i;j;main(n){for(scanf("%d",&n),n%=30;i<n;)c[i++%5+1]^=c[i%5]^=c[i%5+1]^=c[i%5];for(;j<6;)putchar(48+c[j++]);puts("");}
                     ^
./Main.c:1:21: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:23: warning: return type defaults to ‘int’ [-Wimplicit-int]
 c[]={1,2,3,4,5,6};i;j;main(n...