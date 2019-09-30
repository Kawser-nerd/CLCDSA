import numpy as np

A, B = map(int, input().split())
if np.sign(A) == np.sign(B):
    print(B-A)
else:
    print(B-A-1)