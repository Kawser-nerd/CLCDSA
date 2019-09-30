def make(n, r):
    v = {0: 1}
    for _ in range(n):
        s = int(input())
        w = dict(v)
        for k, val in v.items():
            w[k + s] = v.get(k + s, 0) + val
        v = w
    return sorted(v.items(), reverse=r)

N, X = map(int, input().split())
S = make(N//2, 0)
T = make(N - N//2, 1)
ans = 0
it = iter(T)

nn = (None, None)
t, w = next(it, nn)
for s, v in S:
    while w and s + t > X:
        t, w = next(it, nn)
    if w and s + t == X:
        ans += v * w
print(ans)