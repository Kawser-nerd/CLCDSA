n,k=map(int,input().split())

S=[int(input()) for _ in range(n)]

ans=0
res=1
l=0

for r in range(n):
    res*=S[r]
    if res>k:
        res//=S[l]
        l+=1
    ans=max(ans,r-l+1)

if 0 in S:
    print(n)
else:
    print(ans)