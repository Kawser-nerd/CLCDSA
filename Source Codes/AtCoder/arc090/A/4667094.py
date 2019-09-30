import numpy as np
n = int(input())
a1 = np.array([int(i) for i in input().split()])
a2 = np.array([int(i) for i in input().split()])
ans = 0
for i in range(n):
  ans = max(ans,(a1[0:i+1].sum()+a2[i:].sum()))
print(ans)