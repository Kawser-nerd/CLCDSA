N,M=map(int,input().split())
X=[list(map(int,input().split())) for i in range(N)]
check=[list(map(int,input().split())) for i in range(M)]

for x,y in X:
    dist=[abs(x-c[0])+abs(y-c[1]) for c in check]

    MIN=min(dist)

    print(dist.index(MIN)+1)