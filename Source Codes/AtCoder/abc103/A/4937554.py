a, b, c = map(int, input().split())
A = [a, b, c]
A.sort()
ans = 0
for i in range(len(A) - 1):
    ans += A[i + 1] - A[i]
print(ans)