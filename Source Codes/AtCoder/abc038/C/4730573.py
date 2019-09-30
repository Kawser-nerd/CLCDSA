n=int(input())
a=list(map(int,input().split()))
ans=0
before=a[0]
cnt=1
for i in range(1,n):
    if before<a[i]:
        ans+=cnt
        cnt+=1
    else:
        cnt=1
    before=a[i]
print(ans+n)