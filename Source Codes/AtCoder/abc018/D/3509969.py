import itertools

N,M,P,Q,R=map(int,input().split())
XYZ=[list(map(int,input().split())) for i in range(R)]

LIST=[[0 for i in range(N+1)] for j in range(M+1)]
for x,y,z in XYZ:
    LIST[y][x]+=z


ITER=itertools.combinations(range(1,N+1),P)
ANS=0

for ite in ITER:
       
    SCORE=[0]*(M+1)
    for j in range(1,M+1):
        for k in ite:
            SCORE[j]+=LIST[j][k]

    SCORE.sort(reverse=True)
    if ANS<sum(SCORE[:Q]):
        ANS=sum(SCORE[:Q])


print(ANS)