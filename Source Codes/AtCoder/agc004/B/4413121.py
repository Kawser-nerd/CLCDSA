n, x = map(int, input().split())
a = list(map(int, input().split()))

DP = a[:]
ans = sum(DP)
for i in range(n-1):
    new = [0]*n
    for j in range(n):
        new[j] = min(DP[j], DP[j-1])
    DP=new
    ans = min(ans, sum(DP) + (i+1)*x)
print(ans)