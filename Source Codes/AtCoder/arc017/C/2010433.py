from collections import Counter
N,X = map(int,input().split())
ws = [int(input()) for i in range(N)]

H = N//2
res1 = []
for b in range(1 << H):
    w = 0
    for i in range(H):
        if b & (1 << i): w += ws[i]
    res1.append(w)

res2 = []
for b in range(1 << (N-H)):
    w = 0
    for i in range(N-H):
        if b & (1 << i): w += ws[H+i]
    res2.append(w)

ctr = Counter(res1)
ans = 0
for r2 in res2:
    ans += ctr[X - r2]
print(ans)