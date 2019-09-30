n,k = map(int,input().split())
s = [int(input()) for i in range(n)]
if 0 in s:
    print(n)
else:
    r,g,ans = 0,1,0
    for l in range(n):
        while r<n and g*s[r]<=k:
            g*=s[r]
            r+=1
        ans = max(ans,r-l)
        if l==r: r+=1
        else: g//=s[l]
    print(ans)