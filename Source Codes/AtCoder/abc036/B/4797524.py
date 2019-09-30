import numpy as np


N = int(input())
s = np.array([[c for c in input()] for _ in range(N)])
s = np.rot90(s, k =-1)
for i in range(N):
    print("".join(s[i]))