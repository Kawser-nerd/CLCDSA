n,k=map(int,input().split())
A=[list(map(int,input().split())) for i in range(n)]
OK,NG=0,100
for _ in range(100):
    x=(OK+NG)/2
    B=sorted([w*(p-x) for w,p in A],reverse=True)
    if sum(B[:k])>=0:
        OK=x
    else:
        NG=x
print(OK)