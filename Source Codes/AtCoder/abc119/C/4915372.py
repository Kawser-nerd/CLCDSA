from itertools import product
n,a,b,c = map(int,input().split())
l = [int(input()) for i in range(n)]
x = list(product([0, 1, 2, 3], repeat=n))
ans = 10**10
for i in range(len(x)):
    if x[i].count(1) == 0 or x[i].count(2) == 0 or x[i].count(3) == 0:
        continue
    tmpa = 0
    tmpb = 0
    tmpc = 0
    for j in range(n):
        if x[i][j] == 1:
            tmpa += l[j]
        if x[i][j] == 2:
            tmpb += l[j]
        if x[i][j] == 3:
            tmpc += l[j]
    tmpans = abs(a-tmpa)+abs(b-tmpb)+abs(c-tmpc)
    tmpans += (x[i].count(1)-1)*10 + (x[i].count(2)-1)*10 + (x[i].count(3)-1)*10
    ans = min(ans,tmpans)
print(ans)