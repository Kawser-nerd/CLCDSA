i,j;main(a){for(;puts(i?"":"98 99"),i<98;)for(i++%49||scanf("%d",&a),j=0;j<99;)putchar((i%2|j++%2||a--<2)^i>47?35:46);} ./Main.c:1:1: warning: data definition has no type or storage class
 i,j;main(a){for(;puts(i?"":"98 99"),i<98;)for(i++%49||scanf("%d",&a),j=0;j<99;)putchar((i%2|j++%2||a--<2)^i>47?35:46);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 i,j;main(a){for(;puts(i?"":"98 99"),i<98;)for(i++%49||scanf("%d",&a),j=0;j<99;)putchar((i%2|j++%2||a--<2)^i>47?35:46);}
   ^
./Main.c:1:5: warning: return type defaults to ‘int’ [-Wimplicit-int]
 i,j;main(a){for(;puts(i?"":"98 99"),i<98;)for(i++%49||scanf("%d",&a),j=0;j<99;)putchar((i%2|j++%2||a--<2)^i>47?35:46);}
     ^
./Main.c: In function ‘main’:
./Main.c:1:5: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:18: warning: implicit declaration of function ‘puts’ [-Wimplicit-function-declaration]
 i,j;main(a){for(;puts(i?"":"98 99"),i<98;)for(i++%49||scanf("%d",&a),j=0;j<99;)putchar((i%2|j++%2||a--<2)^i>47?35:46);}
                  ^...