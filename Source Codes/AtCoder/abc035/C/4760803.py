import numpy as np

N, Q = list(map(int, input().split()))

_diff = [0]*(N+1)

for _ in range(Q):
  l,r = list(map(int, input().split()))
  _diff[l-1]+=1
  _diff[r]-=1
  
x = np.mod(np.cumsum(np.array(_diff)),2).astype('str')[:-1]
  
print(''.join(x))