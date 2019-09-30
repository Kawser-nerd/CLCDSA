c,s,t,g,h,i,j,b,e,d;char C[9999];Q[9999];R[9999];S(p){R[Q[e++]=i+p]=d+1;}main(){for(scanf("%*d%d%d%d%d%d",&c,&s,&t,&g,&h);~scanf("%s",C+c*j++););for(S(~-s*c+~-t);~-g*c+~-h-i;C[i]&4&&(C[i]=0,S(-c),S(c),S(-1),S(1)))d=R[i=Q[b++]];printf("%d\n",d-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 c,s,t,g,h,i,j,b,e,d;char C[9999];Q[9999];R[9999];S(p){R[Q[e++]=i+p]=d+1;}main(){for(scanf("%*d%d%d%d%d%d",&c,&s,&t,&g,&h);~scanf("%s",C+c*j++););for(S(~-s*c+~-t);~-g*c+~-h-i;C[i]&4&&(C[i]=0,S(-c),S(c),S(-1),S(1)))d=R[i=Q[b++]];printf("%d\n",d-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘s’ [-Wimplicit-int]
 c,s,t,g,h,i,j,b,e,d;char C[9999];Q[9999];R[9999];S(p){R[Q[e++]=i+p]=d+1;}main(){for(scanf("%*d%d%d%d%d%d",&c,&s,&t,&g,&h);~scanf("%s",C+c*j++););for(S(~-s*c+~-t);~-g*c+~-h-i;C[i]&4&&(C[i]=0,S(-c),S(c),S(-1),S(1)))d=R[i=Q[b++]];printf("%d\n",d-1);}
   ^
./Main.c:1:5: warning: type defaults to ‘int’ in declaration of ‘t’ [-Wimplicit-int]
 c,s,t,g,h,i,j,b,e,d;char C[9999];Q[9999];R[9999];S(p){R[Q[e++]=i+p]=d+1;}main(){for(scanf("%*d%d%d%d%d%d",&c,&s,&t,&g,&h);~scanf("%s",C+c*j++););for(S(~-s*c+~-t);~-g*c+~-h-i;C[i]&4&&(C[i]=0,S(-c...