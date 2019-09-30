import numpy as np
N, x = map(int, input().split())
a = np.array(list(map(int, input().split())))
b = np.copy(a)
ans = float('inf') 
for i in range(N):
    c = np.roll(a,i)
    b = np.minimum(b,c)
    ans = min(ans, sum(b)+i*x)
print(ans)