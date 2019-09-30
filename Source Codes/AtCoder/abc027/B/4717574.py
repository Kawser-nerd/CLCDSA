n=int(input())
l=list(map(int,input().split()))
l.append(0)
ans=0
k=sum(l)/n
if k%1!=0:
    print(-1)
else:
    for i in range(1,n):
        if sum(l[:i])==k*i and sum(l[i:])==k*(n-i):
            pass
        else:
            ans+=1
    print(ans)