n=int(input().strip())
a=list(map(int, input().split()))
sumx=a[0]
sumy=sum(a[1:])
ans=abs(sumx-sumy)

for i in range(1,n-1):
    sumx+=a[i]
    sumy-=a[i]
    ans=min(ans,abs(sumx-sumy))
print(ans)