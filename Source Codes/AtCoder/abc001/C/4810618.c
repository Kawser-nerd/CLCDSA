a;b;c;char*s[]={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};t[]={14,92,200,326,476,644,830,1028,1244,1466,1706,1958,12000};main(){scanf("%d%d",&a,&b);;for(a=(a+112)/225;b>t[c++];);printf("%s %d\n",c-1?s[a%16]:"C",c-1);} ./Main.c:1:1: warning: data definition has no type or storage class
 a;b;c;char*s[]={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};t[]={14,92,200,326,476,644,830,1028,1244,1466,1706,1958,12000};main(){scanf("%d%d",&a,&b);;for(a=(a+112)/225;b>t[c++];);printf("%s %d\n",c-1?s[a%16]:"C",c-1);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:1:3: warning: data definition has no type or storage class
 a;b;c;char*s[]={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};t[]={14,92,200,326,476,644,830,1028,1244,1466,1706,1958,12000};main(){scanf("%d%d",&a,&b);;for(a=(a+112)/225;b>t[c++];);printf("%s %d\n",c-1?s[a%16]:"C",c-1);}
   ^
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
./Main.c:1:5: warning: data definition has no type or storage class
 a;b;c;char*s[]={"N","NNE","NE","ENE","E","ESE","SE","SSE","S","SSW","SW","WSW","W","WNW","NW","NNW"};t[]={14,92,200,3...