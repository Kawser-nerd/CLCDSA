n = int(input())
s = list(map(int,input().split()))
p = [0 for i in range(10**5+1)]
r,ans = 0,0
for l in range(n):
    while r<n and p[s[r]]==0:
        p[s[r]]+=1
        r+=1
    ans = max(ans,r-l)
    if l==r: r+=1
    else: p[s[l]]-=1
print(ans)