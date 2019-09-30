import numpy as np
import math

N = int(input())
a = list(map(int, input().split()))
a = np.asarray(a)

ans = 0
while(1):
    if a.max() < N:
        break
    
    for i in range(a.size):
        if a[i] > (N-1):
            diff = math.ceil((a[i] - (N-1))/N)
            
            a[i] -= N * diff
            a[:i] += 1 * diff
            a[i+1:] += 1 * diff

            ans += diff
print(ans)