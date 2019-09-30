from itertools import combinations
n,m,p,q,r = map(int,input().split())
choco = [[0]*m for _ in range(n)]

for _ in range(r):
    x,y,z = map(int,input().split())
    choco[x-1][y-1] = z
ret = 0
for boys in combinations(range(n),p):
    tgtchoco = [0]*m
    for i in boys:
        for j in range(m):
            tgtchoco[j] += choco[i][j]
    ret = max(ret,sum(sorted(tgtchoco,reverse=True)[0:q]))
print(ret)