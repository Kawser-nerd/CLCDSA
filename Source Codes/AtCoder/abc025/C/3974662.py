import copy

B=[list(map(int,input().split())) for i in range(2)]
C=[list(map(int,input().split())) for i in range(3)]

SUM=0
for i in range(2):
    for j in range(3):
        SUM+=B[i][j]
        SUM+=C[j][i]


DPDICT=dict()
SCOREDICT=dict()

def sc(M):
    ANS=0
    for i in range(2):
        for j in range(3):
            if M[i*3+j]==M[(i+1)*3+j]:
                ANS+=B[i][j]

    for i in range(3):
        for j in range(2):
            if M[i*3+j]==M[i*3+j+1]:
                ANS+=C[i][j]

    return ANS
    


def score(M,i):
    if SCOREDICT.get(tuple(M))!=None:
        return SCOREDICT.get(tuple(M))
    if min(M)>0:
        return sc(M)
    if i==1:
        ANS=-float("inf")
        for i in range(9):
            if M[i]==0:
                N=copy.deepcopy(M)
                N[i]=1
                if ANS<score(N,2):
                    ANS=score(N,2)

        SCOREDICT[tuple(M)]=ANS
        return ANS

    if i==2:
        ANS=float("inf")
        for i in range(9):
            if M[i]==0:
                N=copy.deepcopy(M)
                N[i]=2
                if ANS>score(N,1):
                    ANS=score(N,1)

        SCOREDICT[tuple(M)]=ANS
        return ANS
        

M=[0]*9         
t=score(M,1)
print(t)
print(SUM-t)