N, K = map(int,input().split())

if K == 0:
    print(N**2)
    exit()
ans = 0
for b in range(1,N+1):
    p = N//b
    r = N%b
    ans += p*max(0,b-K) + max(0,r-K+1)

print(ans)