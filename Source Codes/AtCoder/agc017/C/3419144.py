from collections import Counter
N,M = map(int,input().split())
A = list(map(int,input().split()))
src = [tuple(map(int,input().split())) for i in range(M)]
ctr = Counter(A)
cover = [0] * (2*N+1)
for k,v in ctr.items():
    for i in range(k,k-v,-1):
        cover[i+N] += 1
ans = cover[N+1:].count(0)

for x,y in src:
    ctr[A[x-1]] -= 1
    ai = A[x-1]+N - ctr[A[x-1]]
    cover[ai] -= 1
    if ai > N and cover[ai] == 0: ans += 1
    A[x-1] = y
    bi = y+N - ctr[y]
    if bi > N and cover[bi] == 0: ans -= 1
    cover[bi] += 1
    ctr[y] += 1
    print(ans)