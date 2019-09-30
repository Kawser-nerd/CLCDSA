n,t=map(int,input().split())
a = [int(input()) for _ in range(n)]

ans = 0
for i in range(len(a)-1):
    if a[i]+t > a[i+1]:
        ans += a[i+1]-a[i]
    else:
        ans += t

ans += t
print(ans)