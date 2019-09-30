import sys
import copy
sys.setrecursionlimit(10**9+7)

l_org=[list(input()) for i in range(10)]

idl=[["x"]*10 for i in range(10)]
dx=[1,0,-1,0]
dy=[0,1,0,-1]
def dfs(y,x):
    if 0<=y<10 and 0<=x<10:
        if l[y][x]=="o":
            l[y][x]="x"
            for k in range(4):
                ny=y+dy[k]
                nx=x+dx[k]
                dfs(ny,nx)
ans="NO"
for cy in range(10):
    for cx in range(10):
        l=copy.deepcopy(l_org)
        l[cy][cx]="o"
        dfs(cy,cx)
        if l==idl:
            ans="YES"
            break
print(ans)