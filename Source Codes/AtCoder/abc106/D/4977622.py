N,M,Q= list(map(int, input().split()))
LR = [list(map(int, input().split())) for _ in range(M)]
PQ = [list(map(int, input().split())) for _ in range(Q)]

import numpy as np
from itertools import combinations

trains = [[0]*N for _ in range(N)]

for l, r in LR:
  trains[l-1][r-1] +=1
  
trains = np.array(trains)

# ??????
row_sum = trains.cumsum(axis=1)
matrix_sum = row_sum.cumsum(axis=0)

answer = {}

for p,q in PQ:
  if (p,q) not in answer:
    if p==1:
      answer[(p,q)] = matrix_sum[q-1, q-1]
    else:
      answer[(p,q)] = matrix_sum[q-1,q-1] - matrix_sum[p-2,q-1]
  print(answer[(p,q)])