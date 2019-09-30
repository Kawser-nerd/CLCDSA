n = int(input())
s = list(map(int,input().split()))
a = [0]*(10**5+1)
ans,r = 0,0
for l in range(n):
    while r<n and a[s[r]]==0:
        a[s[r]]+=1
        r+=1
    ans = max(ans,r-l)
    if r==l: r+=1
    else: a[s[l]]-=1
print(ans)