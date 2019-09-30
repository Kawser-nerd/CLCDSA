z[9999],a,b,c;f(x,y){fflush(!printf("? %d %d\n",x,y));scanf("%s",&b);b=b>78;}main(i){if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return;}for(i=a+=b;~--i;)!c||f(i,z[c-1])?(z[c++]=i):c--;for(c=*z,i=a;~--i;)z[i]=f(c,i);for(printf("! "),i=0;i<a;)printf("%d",z[i++]);} ./Main.c:1:1: warning: data definition has no type or storage class
 z[9999],a,b,c;f(x,y){fflush(!printf("? %d %d\n",x,y));scanf("%s",&b);b=b>78;}main(i){if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return;}for(i=a+=b;~--i;)!c||f(i,z[c-1])?(z[c++]=i):c--;for(c=*z,i=a;~--i;)z[i]=f(c,i);for(printf("! "),i=0;i<a;)printf("%d",z[i++]);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘z’ [-Wimplicit-int]
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 z[9999],a,b,c;f(x,y){fflush(!printf("? %d %d\n",x,y));scanf("%s",&b);b=b>78;}main(i){if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return;}for(i=a+=b;~--i;)!c||f(i,z[c-1])?(z[c++]=i):c--;for(c=*z,i=a;~--i;)z[i]=f(c,i);for(printf("! "),i=0;i<a;)printf("%d",z[i++]);}
         ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 z[9999],a,b,c;f(x,y){fflush(!printf("? %d %d\n",x,y));scanf("%s",&b);b=b>78;}main(i){if(scanf("%d%d",&a,&b),a<=b){puts("Impossible");return;}for(i=...