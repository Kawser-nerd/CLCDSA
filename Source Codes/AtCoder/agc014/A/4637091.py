import numpy as np
A, B, C = map(int, input().split())
A, B, C = np.sort([A, B, C])
ab = B - A 
bc = C - B 
if (A%2 == 1) & (B%2 == 1) & (C%2 == 1):
  print(0)
elif (ab == 0) & (bc == 0):
  print(-1)
else:
  for k in range(30):
    if ((ab % 2) == 1) | ((bc % 2) == 1):
      print(k)
      break
    ab = int(ab/2)
    bc = int(bc/2)