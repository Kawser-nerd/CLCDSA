A, B = map(int, input().split())
if A > B:
    A, B = B, A

import numpy as np
r = (A**2 + B**2)**0.5
alpha = np.arctan(A/B)

N = int(input())

for _ in range(N):
    C, D = map(int, input().split())
    if C > D:
        C, D = D, C
    if C >= A and D >= B:
        print("YES")
    elif C < A and D < B or r < D:
        print("NO")
    elif C >= r * np.cos(np.arcsin(D / r) - 2 * alpha):
        print("YES")
    else:
        print("NO")