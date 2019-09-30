n, x = map(int, input().split())
a = list(map(int, input().split()))
 
b = a[::]
ans = sum(a)
 
for k in range(1, n):
    b = [min(b[i], a[i - k]) for i in range(n)]
    ans = min(ans, sum(b) + k * x)
print(ans)