n, ans = 0, f = 0, a; main() {scanf("%d", &n);for(int i = 1; i <= n; i ++) {scanf("%d", &a);if(a == i) ans += (f ^= 1);else f = 0;}printf("%d\n", ans);} ./Main.c:1:1: warning: data definition has no type or storage class
 n, ans = 0, f = 0, a; main() {scanf("%d", &n);for(int i = 1; i <= n; i ++) {scanf("%d", &a);if(a == i) ans += (f ^= 1);else f = 0;}printf("%d\n", ans);}
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘n’ [-Wimplicit-int]
./Main.c:1:4: warning: type defaults to ‘int’ in declaration of ‘ans’ [-Wimplicit-int]
 n, ans = 0, f = 0, a; main() {scanf("%d", &n);for(int i = 1; i <= n; i ++) {scanf("%d", &a);if(a == i) ans += (f ^= 1);else f = 0;}printf("%d\n", ans);}
    ^
./Main.c:1:13: warning: type defaults to ‘int’ in declaration of ‘f’ [-Wimplicit-int]
 n, ans = 0, f = 0, a; main() {scanf("%d", &n);for(int i = 1; i <= n; i ++) {scanf("%d", &a);if(a == i) ans += (f ^= 1);else f = 0;}printf("%d\n", ans);}
             ^
./Main.c:1:20: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 n, ans = 0, f = 0, a; main() {scanf("%d", &n);for(int i = 1; i <= n; i ++) {scanf("%d", &a);if(a == i) ans += (f ^= 1);else f...