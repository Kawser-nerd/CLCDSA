N,M=list(map(int,input().split()))
W=[list(map(lambda x:int(x)-1,input().split())) for _ in range(M)]
BOX=[[1,1]]
BOX.extend([[1,0] for _ in range(N)])
for i in range(M):
    BOX[W[i][0]][0]=BOX[W[i][0]][0]-1
    BOX[W[i][1]][0]=BOX[W[i][1]][0]+1
    if(BOX[W[i][0]][1]==1):
        BOX[W[i][1]][1]=1
        if(BOX[W[i][0]][0]==0):
            BOX[W[i][0]][1]=0
print(sum(list(map(lambda x:x[:][1],BOX))))