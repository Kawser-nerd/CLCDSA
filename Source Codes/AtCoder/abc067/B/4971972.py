N,K = map(int,input().split())
L = list(map(int,input().split()))
L.sort(reverse=True)

Ans = 0
for i in range(K):
    Ans += L[i]

print(Ans)