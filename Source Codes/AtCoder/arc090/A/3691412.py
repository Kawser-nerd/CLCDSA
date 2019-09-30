import numpy as np
def inpl(): return [int(i) for i in input().split()]

N = int(input())
A1 = np.cumsum(np.array(inpl()))
A2 = np.cumsum(np.array(inpl()))
ans = A1[0] + A2[-1]
for i in range(1,N):
    ans = max(ans, A1[i]+A2[-1]-A2[i-1])
print(ans)