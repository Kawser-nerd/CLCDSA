import numpy as np
N = int(input())
R = sorted([int(input()) for _ in range(N)], reverse = True)
area = 0
flag = True
for r in R:
    if flag:
        area += r**2 * np.pi
    else:
        area -= r**2 * np.pi
    flag = not flag
print(area)