N,K=map(int,input().split())
A=[int(i) for i in input().split()]
ans=0
for i in range(40,-1,-1):
    bit=0
    for a in A:
        bit+=((a>>i)&1)
    cond=2**i
    if (N-bit)>bit and K>=cond:
        ans+=(N-bit)*cond
        K-=cond
    else:
        ans+=bit*cond
print(ans)