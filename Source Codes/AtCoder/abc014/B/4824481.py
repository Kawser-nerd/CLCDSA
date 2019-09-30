n, X = map(int, input().split())
A = list(map(int, input().split()))

X = bin(X)[2:].zfill(len(A))
ans = 0
for i in range(len(A)):
    if X[len(A)-i-1] == '1':
        ans += A[i]

print(ans)