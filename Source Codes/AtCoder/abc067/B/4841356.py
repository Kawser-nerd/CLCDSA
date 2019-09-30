#67
n, k = map(int, input().split()) 
a = list(map(int, input().split()))
a.sort()
ans = 0
for i in range(n-k,n):
    ans += a[i]
print(ans)