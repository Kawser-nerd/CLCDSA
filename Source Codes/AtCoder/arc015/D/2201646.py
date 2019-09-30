# seishin.py
T, N, P = input().split()
T = int(T); N = int(N); P = float(P)
D = []
for i in range(N):
    q, x, t = input().split()
    q = float(q); x = int(x); t = int(t)
    D.append((t, x, q))
D.sort()

cur = 1 - P + P*sum(x*q for t, x, q in D)
j = 0
ans = 0.
res = 1.
for y in range(T):
    while j < N and D[j][0] <= y:
        t, x, q = D[j]
        cur += P*q*(1-x)
        j += 1
    ans += res
    res *= cur
print("%.08f" % ans)