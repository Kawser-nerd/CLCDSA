n,t = map(int,input().split())
l = list(map(int,input().split()))
ans = t
for i in range(1,n):
    if l[i]-l[i-1]<t:
        ans -= t-(l[i]-l[i-1])
    ans += t
print(ans)