n,k = map(int,input().split())
a = list(map(int,input().split()))

s = sum(i for i in a if i > 0)

ans = 0
psum = 0
asum = 0
for i in range(n-k+1):
    if i == 0:
        for j in range(k):
            if a[j]>0:
                psum += a[j]
            asum += a[j]
    else:
        if a[i-1] > 0:
            psum -= a[i-1]
        asum -= a[i-1]
        if a[i+k-1] > 0:
            psum += a[i+k-1]
        asum += a[i+k-1]
    ans = max(ans, s - psum +[0,asum][asum>0])
print(ans)