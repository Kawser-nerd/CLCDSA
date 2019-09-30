n = int(input())
s = list(map(int,input().split()))
r,ans = 1,0
for l in range(n):
    while r<n and (r<=l or s[r-1]<s[r]):
        r+=1
    ans += r-l
    if l==r: r+=1
print(ans)