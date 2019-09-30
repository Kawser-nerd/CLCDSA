import numpy as np
 
N, K = [int(i) for i in input().split()]
ab = np.array(
  [[int(i) for i in input().split()] for _ in range(N)])
 
idx_ab = np.argsort(ab[:, 0])
ab = ab[idx_ab, :]

k_sum = 0
 
for record in ab:
  a = record[0]
  b = record[1]
  
  k_sum += b
  if k_sum >= K:
    print(a)
    break