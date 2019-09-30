N=int(input())
a=list(map(int,input().split()))

max=sum(a)
s=a[0]
ans=abs(2*s-max)
for i in range(1,N-1):
    s+=a[i]
    ans=min(ans,abs(2*s-max)) 
print(ans)