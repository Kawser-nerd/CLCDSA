N,K = map(int,input().split())
A = list(map(int,input().split()))
ans = 1
n = N-K
ans += n//(K-1)
ans += 1 if n%(K-1) != 0 else 0
print(ans)