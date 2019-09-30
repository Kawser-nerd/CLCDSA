import numpy as np
N = int(input())
S = np.array([list(input()) for _ in range(N)]) 
ans = 0
for i in range(N):
    S = np.roll(S, 1, axis = 1)
    if (S != S.T).any():
        continue
    ans += 1
print(ans * N)