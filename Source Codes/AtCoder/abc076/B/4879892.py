N = int(input())
K = int(input())

ans = 1
for i in range(N):
    a = 2*ans
    b = ans + K
    ans = min(a, b)

print(ans)