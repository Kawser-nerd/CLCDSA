N,MA,MB=map(int,input().split())
S=[list(map(int,input().split())) for i in range(N)]

DPLIST=[[10**6 for i in range(401)] for j in range(401)]
DPLIST[0][0]=0

for a,b,c in S:
    for i in range(400,a-1,-1):
        for j in range(400,b-1,-1):
            if DPLIST[i][j]>DPLIST[i-a][j-b]+c:
                DPLIST[i][j]=DPLIST[i-a][j-b]+c
                
ANS=10**6
for k in range(1,400//max(MA,MB)):
    if DPLIST[MA*k][MB*k]<ANS:
        ANS=DPLIST[MA*k][MB*k]

if ANS==10**6:
    print(-1)
else:
    print(ANS)