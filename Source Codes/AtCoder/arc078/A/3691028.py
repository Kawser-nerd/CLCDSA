def inpl(): return [int(i) for i in input().split()]
import numpy as np
ans = float('inf')
N = int(input())
a = np.cumsum(np.array(inpl()))
suma = a[-1]
a = np.delete(a, -1)
for i in a:
    ans = min(ans, abs(suma-2*i))
print(ans)