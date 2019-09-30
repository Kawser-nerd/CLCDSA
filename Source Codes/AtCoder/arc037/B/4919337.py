def notwent(camefrom):
    for i,j in enumerate(camefrom):
        if j==N:
            return(i)

import numpy as np
from collections import deque
import sys
fastinput=sys.stdin.readline
#?????????
N,M=map(int,fastinput().split())#Ai?Aj????????A[i][j]=A[j][i]=1
Lines=[[False]*N for i in range(N)]
ans=0
for _ in range(M):
    u,v=[int(i)-1 for i in fastinput().split()]
    Lines[u][v]=True
    Lines[v][u]=True#???Ai???????????????
camefrom=[N]*N
togo=deque()
while not all([apijwe!=N for apijwe in camefrom]):
    curpos=notwent(camefrom)
    togo.append(curpos)
    itsloop=0
    camefrom[curpos]=curpos
    while togo:
        curpos=togo.pop()
        for to,p in enumerate(Lines[curpos]):
            if p and to!=camefrom[curpos]:
                if camefrom[to]!=N and itsloop==0:
                    ans-=1
                    itsloop=1
                elif camefrom[to]==N:
                    togo.append(to)
                    camefrom[to]=curpos
    ans+=1
print(ans)