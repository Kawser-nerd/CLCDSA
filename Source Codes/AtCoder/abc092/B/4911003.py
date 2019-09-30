N, D, X, *A = map(int, open(0).read().split())
ans = X
for i in range(N):
    ans += 1+(D-1)//A[i]
print(ans)