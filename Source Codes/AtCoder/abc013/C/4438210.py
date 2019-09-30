import sys
inp = sys.stdin.readline

N, H = map(int,inp().split())
A, B, C, D, E = map(int,inp().split())
h = H

K = N*E-H
B += E
D += E

if(H-E*N > 0):
  print(0)
else:
  m = 10000000000000
  for i in range(N+1):
    if(K-(B*i) <= 0):
      m = min(m, (A*i))
    else:
      m = min(m, (K-(B*i))//D*C+C+A*i)
  print(m)