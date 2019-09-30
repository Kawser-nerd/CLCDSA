import itertools
N,M,L = map(int,input().split())
P,Q,R = map(int,input().split())
K = [P,Q,R]
S = list(itertools.permutations(K))
ans = 0
for i in range(6):
  mul = (N//S[i][0])*(M//S[i][1])*(L//S[i][2])
  if ans <= mul:
    ans = mul
print(ans)