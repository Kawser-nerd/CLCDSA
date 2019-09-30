M=1e9+7,A[1<<17],B[1<<17],i,j,f;main(s){for(gets(&f);~scanf("%d",&f);B[f]=++i)s=((A[i+1]=(A[i]+s)%M)-A[j=fmax(j,B[f])]+M)%M;printf("%d\n",s);} ./Main.c:1:1: warning: data definition has no type or storage class
 M=1e9+7,A[1<<17],B[1<<17],i,j,f;main(s){for(gets(&f);~scanf("%d",&f);B[f]=++i)s=((A[i+1]=(A[i]+s)%M)-A[j=fmax(j,B[f])]+M)%M;printf("%d\n",s);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘M’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
 M=1e9+7,A[1<<17],B[1<<17],i,j,f;main(s){for(gets(&f);~scanf("%d",&f);B[f]=++i)s=((A[i+1]=(A[i]+s)%M)-A[j=fmax(j,B[f])]+M)%M;printf("%d\n",s);}
         ^
./Main.c:1:18: warning: type defaults to ‘int’ in declaration of ‘B’ [-Wimplicit-int]
 M=1e9+7,A[1<<17],B[1<<17],i,j,f;main(s){for(gets(&f);~scanf("%d",&f);B[f]=++i)s=((A[i+1]=(A[i]+s)%M)-A[j=fmax(j,B[f])]+M)%M;printf("%d\n",s);}
                  ^
./Main.c:1:27: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 M=1e9+7,A[1<<17],B[1<<17],i,j,f;main(s){for(gets(&f);~scanf("%d",&f);B[f]=++i)s=((A[i+1]=(A[i]+s)%M)-A[j=fmax(j,B[f])]+M)%M;printf("%d\n",s);}
    ...