n = int(input())
u = 0
dmax = 0
for i in range(2, n+1):
    print("?", 1, i, flush=True)
    d = int(input())
    if d > dmax:
        dmax = d
        u = i
ans = 0
for i in range(1, n+1):
    if i == u:
        continue
    print("?", u, i, flush=True)
    ans = max(ans, int(input()))
print("!", ans)