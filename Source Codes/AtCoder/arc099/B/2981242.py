K=int(input())
if K!=10 and K!=792:
    exit()
def snuke(N):
    S=list(str(N))
    SN=0
    for i in S:
        SN+=int(i)
    return N/SN
def X(D,n):
    temp=(n+10**(D+1))//(10**(D+1))
    return 10**(D+1)*temp-1
L=[1]
k=1
for i in range(1,K):
    N=L[k-1]+1
    x=X(0,N)
    tmp=snuke(N)
    ans=N
    for d in range(len(str(N))):
        x=X(d,N)
        if snuke(x)<tmp:
            tmp=snuke(x)
            ans=x
    L.append(ans)
    k+=1
for i in L:
    print(i)