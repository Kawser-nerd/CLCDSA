x[999];i;j;s;t;M;main(k){for(gets(x);~scanf("%d%d",x+i,x+i+1);i+=2);for(;j<i;j+=2)for(k=j;k<i;M=fmax(M,s*s+t*t),k+=2)t=x[j+1]-x[k+1],s=x[j]-x[k];printf("%f\n",sqrt(M));} ./Main.c:1:1: warning: data definition has no type or storage class
 x[999];i;j;s;t;M;main(k){for(gets(x);~scanf("%d%d",x+i,x+i+1);i+=2);for(;j<i;j+=2)for(k=j;k<i;M=fmax(M,s*s+t*t),k+=2)t=x[j+1]-x[k+1],s=x[j]-x[k];printf("%f\n",sqrt(M));}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘x’ [-Wimplicit-int]
./Main.c:1:8: warning: data definition has no type or storage class
 x[999];i;j;s;t;M;main(k){for(gets(x);~scanf("%d%d",x+i,x+i+1);i+=2);for(;j<i;j+=2)for(k=j;k<i;M=fmax(M,s*s+t*t),k+=2)t=x[j+1]-x[k+1],s=x[j]-x[k];printf("%f\n",sqrt(M));}
        ^
./Main.c:1:8: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:10: warning: data definition has no type or storage class
 x[999];i;j;s;t;M;main(k){for(gets(x);~scanf("%d%d",x+i,x+i+1);i+=2);for(;j<i;j+=2)for(k=j;k<i;M=fmax(M,s*s+t*t),k+=2)t=x[j+1]-x[k+1],s=x[j]-x[k];printf("%f\n",sqrt(M));}
          ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
./Main.c:1:12: warning: d...