a,k=map(int,input().split())
m=2*10**12
if k==0:
    ans=m-a
else:
    ans=0
    while a<m:
        a+=1+k*a
        ans+=1
print(ans)