inpl = lambda: list(map(int,input().split()))

H, W = inpl()
A = []
for _ in range(H):
    A.append(inpl())

def pos(n):
    q, m = divmod(n, W)
    if q % 2:
        m = (W-1) - m
    return q, m

ans = []
f = 0
hn, wn = 0, 0
for n in range(H*W-1):
    h, w = hn, wn
    hn, wn = pos(n+1)
    if (f+A[h][w]) % 2:
        ans.append([h+1,w+1,hn+1,wn+1])
        f = 1
    else:
        f = 0

print(len(ans))
for rec in ans:
    print(rec[0],rec[1],rec[2],rec[3])