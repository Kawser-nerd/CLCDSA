from itertools import combinations
N,M,P,Q,R=map(int,input().split())
zmat = [[0 for i in range(M)] for j in range(N)]
z_max = 0
for i in range(R):
  x,y,z=map(int,input().split())
  zmat[x-1][y-1] = z
for nc in combinations(range(N),P):
  yz = []
  for ni in nc:
    yz.append(zmat[ni])
  z_max = max(z_max, sum(sorted(map(sum, zip(*yz)), reverse=True)[0:Q]))
print(z_max)