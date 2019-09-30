from math import pi

N, Q = map(int, input().split())
C = []
for i in range(N):
  C.append(list(map(int, input().split())))
  
P = []
for i in range(Q):
  P.append(list(map(int, input().split())))
  
for i in range(Q):
  A, B = P[i]
  ans = 0
  for j in range(N):
    X, R, H = C[j]
    if B<=X or X+H<=A:
      continue
    #if X<=A and B<=X+H:
    ans += ((R**2) * H * pi / 3) * (min(H,(X+H-A))**3 - max(0,(X+H-B))**3) / H**3
  print(ans)