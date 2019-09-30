from fractions import Fraction
import math
import sys
sys.setrecursionlimit(1000*100)

ids=list()
pos=dict()
N=int(input())
path=[]
for _ in range(0,N):
    a=input().split()
    l=a[0]
    m=int(a[1])
    s=a[2]
    if not l in pos:
        pos[l]=len(ids)
        ids.append(l)
        path.append(list())
    if not s in pos:
        pos[s]=len(ids)
        ids.append(s)
        path.append(list())
    path[pos[l]].append((pos[s],Fraction(m,1)))
    path[pos[s]].append((pos[l],Fraction(1,m)))

dist=[None for _ in range(0,len(ids))]

I=0
J=0
def dfs(i,d):
    global I,J
    dist[i]=d
    if dist[I]<d:
        I=i
    if dist[J]>d:
        J=i
    for j,e in path[i]:
        if dist[j] is None:
            dfs(j,d*e)

dfs(0,Fraction(1,1))
print(1,ids[J],'=',math.floor(dist[I]/dist[J]),ids[I],sep='')



#c=int(input())
#a,b=tuple(map(int,input().split()))
#edges=dict((i,[]) for i in range(1,c+1))
#children=filter(lambda x: x != p, edges[r])
#cs.sort(key=lambda x:Fraction(x[0],x[1]),reverse=True)
#if dp[r] is not None:
#chr(ord('a')+1)
#''.join(['a','b','c'])
#sys.exit()