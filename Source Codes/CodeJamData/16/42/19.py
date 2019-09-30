from itertools import *

def test(k):
    assert(len(k) == K)
    F = [0.0] * (K//2+1)
    F[0] = 1.0
    for p in k:
        G = [0.0] * (K//2 + 1)
        for j in range(K // 2):
            G[j] += F[j] * p
            G[j+1] += F[j] * (1-p)
        G[K//2] += F[K//2] * p
        F = G
    return F[K//2]


T=int(input())
for t in range(T):
    N,K=map(int,input().split())
    F=list(map(float,input().split()))
    F.sort()
    ans = 0.0
    ans = max(test(F[:K]),test(F[-K:]))
    for i in range(1,K):
        ans = max(ans,test(F[:i] + F[-(K-i):]))
    for i in range(N-K):
        ans = max(ans,test(F[i:i+K]))
    print("Case #%d: %.20f" % (t+1,ans))

