def det(a):
    n=len(a)
    if n==1:
        return a[0][0]
    b=[[a[i][j] for i in range(n)] for j in range(n)]
    k=-1
    for i in range(n):
        if b[i][0]==1:
            k=i
            break
    if k==-1:
        return 0
    else:
        for j in range(n):
            b[k][j],b[0][j]=b[0][j],b[k][j]
    for i in range(1,n):
        if b[i][0]==1:
            for j in range(n):
                b[i][j]=(b[i][j]+b[0][j])%2
    c=[[b[i][j] for i in range(1,n)] for j in range(1,n)]
    return det(c)
N=int(input())
a=[[int(i) for i in list(input())] for j in range(N)]
ans=det(a)
if ans==1:
    print("Odd")
else:
    print("Even")