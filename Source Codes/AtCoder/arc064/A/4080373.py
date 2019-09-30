n,x = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
for i in range(1,n):
    if a[i-1] >  x:
        ans += a[i-1] -x + a[i]
        a[i-1] = x
        a[i] = 0
    elif a[i-1] + a[i] > x:
        ans += a[i-1]+a[i]-x
        a[i] = x-a[i-1]
print(ans)