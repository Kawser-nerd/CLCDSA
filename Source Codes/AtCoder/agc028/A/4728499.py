import sys
import fractions
N, M = map(int, input().split())
S = input()
T = input()

g = fractions.gcd(N, M)
L = N * M // g

def check(U1, U2):
  s1 = L // len(U1)
  s2 = L // len(U2)
  for i in range(len(U1)):
    if (i * s1) % s2 == 0:
      j = (i * s1) // s2
      if U1[i] != U2[j]:
        return False
  return True

if check(S, T) and check(T, S):
  print(L)
else:
  print(-1)