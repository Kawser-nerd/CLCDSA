#24
n, t = map(int, input().split())
a = []
for i in range(n):
    a.append(int(input()))
ans = 0
for i in range(1,n):
    ans += min(a[i]-a[i-1], t)
print(ans+t)