#define N 200010
#define F(o, p) for (int o = 1; o <= p; o++)
#define X(a, b) F[a][b]
#define I scanf
a, b, c, d, g, h, l, m, n, u, v, w, q, E[N], S[N], D[N], X(N, 22);
z(x) { return E[x] == x ? x : (E[x] = z(E[x])); }
main() {
  I("%d%d", &n, &m);
  g = n + 1;
  F(i, n)
  E[i] = i,
  S[i] = 1;
  F(i, m) {
    I("%d%d", &a, &b);
    u = z(a), v = z(b);
    u != v ? D[X(u, 0) = F[v][0] = E[u] = E[v] = E[g] = g] = i, S[g++] = S[v] + S[u] : 0;
  }
  g--;
  X(g, 0) = g;
  h = 21;
  F(j, h)
  F(i, g)
  X(i, j) = X(X(i, j - 1), j - 1);
  I("%d", &q);
  F(i, q) {
    I("%d%d%d", &a, &b, &c);
    n = 0, m = g + 1;
    F(j, 30) {
      l = (n + m) / 2, u = a, v = b;
      for (d = h; ~d; d--) {
        D[w = X(u, d)] <= l ? u = w : 0;
        D[w = X(v, d)] <= l ? v = w : 0;
      }
      (u == v ? S[u] : (S[u] + S[v])) < c ? (n = l) : (m = l);
    }
    printf("%d\n", m);
  }
} ./Main.c:5:1: warning: data definition has no type or storage class
 a, b, c, d, g, h, l, m, n, u, v, w, q, E[N], S[N], D[N], X(N, 22);
 ^
./Main.c:5:1: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
./Main.c:5:4: warning: type defaults to ‘int’ in declaration of ‘b’ [-Wimplicit-int]
 a, b, c, d, g, h, l, m, n, u, v, w, q, E[N], S[N], D[N], X(N, 22);
    ^
./Main.c:5:7: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 a, b, c, d, g, h, l, m, n, u, v, w, q, E[N], S[N], D[N], X(N, 22);
       ^
./Main.c:5:10: warning: type defaults to ‘int’ in declaration of ‘d’ [-Wimplicit-int]
 a, b, c, d, g, h, l, m, n, u, v, w, q, E[N], S[N], D[N], X(N, 22);
          ^
./Main.c:5:13: warning: type defaults to ‘int’ in declaration of ‘g’ [-Wimplicit-int]
 a, b, c, d, g, h, l, m, n, u, v, w, q, E[N], S[N], D[N], X(N, 22);
             ^
./Main.c:5:16: warning: type defaults to ‘int’ in declaration of ‘h’ [-Wimplicit-int]
 a, b, c, d, g, h, l, m, n, u, v, w, q, E[N], S[N], D...