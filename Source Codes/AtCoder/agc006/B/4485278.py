n,x=map(int,input().split())
A=[i for i in range(1,2*n)]
if x==1 or x==2*n-1:
    print('No')
else:
    print('Yes')
    if n==2:
        print(*A,sep='\n')
    else:
        if x==2:
            T=[3,2,1,4]
        else:
            T=[x-1,x,x+1,x-2]
        S=list(set(A)-set(T))
        ans=S[:n-2]+T+S[n-2:]
        print(*ans,sep='\n')