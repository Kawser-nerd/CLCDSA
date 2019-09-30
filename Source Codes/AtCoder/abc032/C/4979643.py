n,k,*s=map(int,open(0).read().split())
 
ans = 0
x = 1
l = 0

for r in range(n):
    x*=s[r]
    if x>k:
        x//=s[l]
        l+=1
    ans=max(ans,r-l+1)
if 0 in s:
    print(len(s))
else:
    print(ans)