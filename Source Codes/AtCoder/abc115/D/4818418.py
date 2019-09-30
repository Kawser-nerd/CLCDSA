def f(level,x):
    if level==0: return x

    if x in [1,0]:
        return 0
    elif x==b[level][0]:
        return b[level][1]
    elif 2<=x<b[level-1][0]+2:
        return f(level-1,x-1)
    elif x==b[level-1][0]+2:
        return b[level-1][1]+1
    elif b[level-1][0]+2<x<b[level][0]:
        return b[level-1][1]+1+f( level-1, x-(b[level-1][0]+2))

N,X=map(int,input().split())
b=[[1,1] for i in range(N+1)]
for i in range(1,N+1):
    b[i][0]=b[i-1][0]*2+3
    b[i][1]=b[i-1][1]*2+1

print(f(N,X))