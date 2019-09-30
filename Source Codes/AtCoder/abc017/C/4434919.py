import sys
inp = sys.stdin.readline

N, M = map(int,inp().split())
LRS = [list(map(int,inp().split())) for _ in range(N)]

max_score = 0
imos = [0] * (M+1)
for l, r, s in LRS:
  l -= 1
  imos[l] += s
  imos[r] -= s
  max_score += s

for i in range(M):
  imos[i+1] += imos[i] 

print(max_score-min(imos[:-1]))