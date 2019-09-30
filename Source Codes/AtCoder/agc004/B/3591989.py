def inpl(): return [int(i) for i in input().split()]
import numpy as np
N, x = inpl()
a = np.array(inpl())
b = np.copy(a)
ans = float('inf') 
for i in range(N):
    c = np.roll(a,i)
    b = np.minimum(b,c)
    ans = min(ans, sum(b)+i*x)
print(ans)