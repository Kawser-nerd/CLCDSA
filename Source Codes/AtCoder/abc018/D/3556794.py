import itertools
n,m,p,q,r = map(int,input().split())
x = [list(map(int,input().split())) for i in range(r)]
c = list(itertools.combinations(range(n),p))
wata = [[0]*m for i in range(n)]
MAX = 0
for i in x:
  wata[i[0]-1][i[1]-1] += i[2]
for i in c:
  mora = [0]*m
  for j in i:
    for k in range(m):
      mora[k] += wata[j][k]
  mora.sort()
  mora = mora[::-1]
  mora = mora[:q]
  MAX = max(MAX,sum(mora))
print(MAX)