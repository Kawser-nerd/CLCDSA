N=int(input())
A=[int(input()) for i in range(N)]
if A[0]!=0:
    print(-1)
else:
    flag=0
    for i in range(1,N):
        if A[i]-A[i-1]>1:
            flag=1
            break
    if flag==1:
        print(-1)
    else:
        ans=0
        for i in range(1,N):
            if A[i-1]+1==A[i]:
                ans+=1
            else:
                ans+=A[i]
        print(ans)