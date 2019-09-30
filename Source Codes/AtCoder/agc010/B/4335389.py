n=int(input())
A=list(map(int,input().split()))
s=sum(A)
if s%((n*(n+1))//2):
    print('NO')
else:
    k=s//(n*(n+1)//2)
    D=[]
    for i in range(n-1):
        D.append(A[i+1]-A[i]-k)
    D.append(A[0]-A[n-1]-k)
    ans='YES'
    for i in range(n):
        if D[i]>0 or D[i]%n!=0:
            ans='NO'
    print(ans)