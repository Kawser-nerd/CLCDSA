import fractions
N, M = map(int, input().split())
S = input()
T = input()
g = fractions.gcd(N, M)
n = N // g
m = M // g
out = n * m * g
for k in range(g):
  if S[k * n] != T[k * m]:
    out = -1
    break
print(out)