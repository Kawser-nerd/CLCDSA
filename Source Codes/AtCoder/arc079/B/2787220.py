import numpy as np
k=int(input())
n=50
res=np.array([i + k // n for i in range(50)])
k %= n
for i in range(k):
    res[i] += n+1
    res -=1

print(n)
print(" ".join(map(str,res)))