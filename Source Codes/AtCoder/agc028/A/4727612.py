import sys
import fractions
N, M = map(int, input().split())
S = input()
T = input()

g = fractions.gcd(N, M)
L = N * M // g

ss = L // N
ts = L // M
for i in range(N):
  if (i * ss) % ts == 0:
    j = (i * ss) // ts
    if S[i] != T[j]:
      print(-1)
      sys.exit()

for i in range(M):
  if (i * ts) % ss == 0:
    j = (i * ts) // ss
    if T[i] != S[j]:
      print(-1)
      sys.exit()

print(L)