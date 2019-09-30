import sys
input=sys.stdin.readline
def det(A):
    l=len(A)
    if l==1:
        return A[0][0]
    B=[[A[i][j] for i in range(l)] for j in range(l)]
    for i in range(l):
        if B[i][0]==1:
            break
    else:
        return 0
    for j in range(l):
        B[i][j],B[0][j]=B[0][j],B[i][j]
    for i in range(1,l):
        if B[i][0]==1:
            for j in range(l):
                B[i][j]^=B[0][j]
    C=[[B[i][j] for i in range(1,l)] for j in range(1,l)]
    return det(C)

n=int(input())
A=[list(map(int,input().replace('\n',''))) for _ in range(n)]
print('Odd' if det(A) else 'Even')