n = int(input())
a = [ int(i) for i in input().split() ]
a = sorted(a)
ans = 0
for i in range(1,n):
    ans += a[i] - a[i-1]
print(ans)