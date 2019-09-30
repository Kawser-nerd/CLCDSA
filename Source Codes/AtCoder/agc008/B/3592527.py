def inpl(): return [int(i) for i in input().split()]

N, K = inpl()
a = inpl()
b = [i if i>0 else 0 for i in a ]
c = [i if i<0 else 0 for i in a ]
d = [0 for _ in range(N-K+1)]
d[0] = sum(c[:K])
e = [0 for _ in range(N-K+1)]
e[0] = sum(b[:K])
for i in range(N-K):
    d[i+1] = d[i] - c[i] + c[i+K]
    e[i+1] = e[i] - b[i] + b[i+K]
print(max(0, sum(b)+max(d), sum(b)-min(e)))