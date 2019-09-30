N,K=map(int,input().split())
X=[tuple(map(int,input().split())) for i in range(N)]
left=0
right=100
while((right-left)>10**(-12)):
    mid=(left+right)/2
    Y=sorted([seq[0]*(seq[1]-mid) for seq in X],reverse=True)
    tmp=sum(Y[:K])
    if tmp>0:
        left=mid
    else:
        right=mid
print(right)