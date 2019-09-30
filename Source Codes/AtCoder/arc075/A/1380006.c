M;s;x[101];i;n;main(a){for(;~scanf("%d",&a);x[i++]=a)n?s+=a:(n=a);for(M=s%10?s:0,i=0;i++<n;)M=fmax(M,(s-x[i])%10?s-x[i]:0);printf("%d",M);} ./Main.c:1:1: warning: data definition has no type or storage class
 M;s;x[101];i;n;main(a){for(;~scanf("%d",&a);x[i++]=a)n?s+=a:(n=a);for(M=s%10?s:0,i=0;i++<n;)M=fmax(M,(s-x[i])%10?s-x[i]:0);printf("%d",M);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 M;s;x[101];i;n;main(a){for(;~scanf("%d",&a);x[i++]=a)n?s+=a:(n=a);for(M=s%10?s:0,i=0;i++<n;)M=fmax(M,(s-x[i])%10?s-x[i]:0);printf("%d",M);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 M;s;x[101];i;n;main(a){for(;~scanf("%d",&a);x[i++]=a)n?s+=a:(n=a);for(M=s%10?s:0,i=0;i++<n;)M=fmax(M,(s-x[i])%10?s-x[i]:0);printf("%d",M);}
     ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:12: warning: data definition has no type or storage class
 M;s;x[101];i;n;main(a){for(;~scanf("%d",&a);x[i++]=a)n?s+...