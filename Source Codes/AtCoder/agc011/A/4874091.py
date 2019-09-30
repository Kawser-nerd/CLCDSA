N,C,K = map(int,input().split())
T = [int(input()) for i in range(N)]
T.sort()
s = 0
e = T[0]+K
p = 0
ans = 0
for i in range(N):
    if p == C or e < T[i]:
        ans += 1
        s = T[i]
        e = T[i]+K
        p = 0
    s = max(s,T[i])
    e = min(e,T[i]+K)
    p += 1
print(ans+1)