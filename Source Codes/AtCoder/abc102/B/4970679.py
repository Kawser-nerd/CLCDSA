N = int(input())
A = list(map(int, input().split()))

ans = 0
for i in range(N-1):
    for j in range(i, N):
        ans = abs(A[i]-A[j]) if abs(A[i]-A[j]) > ans else ans
print(ans)