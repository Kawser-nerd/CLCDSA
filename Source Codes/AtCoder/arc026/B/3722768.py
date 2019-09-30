import numpy as np
N = int(input())
ans = -N 
N_sqrt = int(np.sqrt(N))
for i in range(1, N_sqrt + 1):
    if N % i == 0:
        ans +=  i + N //i 
if N_sqrt**2 == N:
    ans -= N_sqrt

if ans < N:
    print("Deficient")
elif ans == N:
    print("Perfect")
else:
    print("Abundant")