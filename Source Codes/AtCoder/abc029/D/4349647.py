N=int(input())
ans=0
for k in range(9):
    ans+=10**k*(N//(10**(k+1)))
    if N%(10**(k+1))>=10**k:
        ans+=min(2*10**k,N%(10**(k+1))+1)-10**k
print(ans)