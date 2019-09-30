t[2401];u;v;w;main(s,e){for(gets(&s);~scanf("%d-%d",&s,&e);e+=(e%100+4)%60<4?44:4,t[e/5*5]--)t[s/5*5]++;for(;u-2401;v+=t[u++])v?v+t[u]?:printf("%04d-%04d\n",w,u):t[u]?w=u:0;} ./Main.c:1:1: warning: data definition has no type or storage class
 t[2401];u;v;w;main(s,e){for(gets(&s);~scanf("%d-%d",&s,&e);e+=(e%100+4)%60<4?44:4,t[e/5*5]--)t[s/5*5]++;for(;u-2401;v+=t[u++])v?v+t[u]?:printf("%04d-%04d\n",w,u):t[u]?w=u:0;}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
./Main.c:1:9: warning: data definition has no type or storage class
 t[2401];u;v;w;main(s,e){for(gets(&s);~scanf("%d-%d",&s,&e);e+=(e%100+4)%60<4?44:4,t[e/5*5]--)t[s/5*5]++;for(;u-2401;v+=t[u++])v?v+t[u]?:printf("%04d-%04d\n",w,u):t[u]?w=u:0;}
         ^
./Main.c:1:9: warning: type defaults to ‘int’ in declaration of ‘u’ [-Wimplicit-int]
./Main.c:1:11: warning: data definition has no type or storage class
 t[2401];u;v;w;main(s,e){for(gets(&s);~scanf("%d-%d",&s,&e);e+=(e%100+4)%60<4?44:4,t[e/5*5]--)t[s/5*5]++;for(;u-2401;v+=t[u++])v?v+t[u]?:printf("%04d-%04d\n",w,u):t[u]?w=u:0;}
           ^
./Main.c:1:11: warning: type defaults to ‘int’ in declaration of ‘v’ [-Wimplicit-int]
./Main.c...