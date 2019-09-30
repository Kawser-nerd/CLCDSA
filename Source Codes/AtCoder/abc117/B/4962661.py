import numpy as np

N = int(input())
L = np.array([int(s) for s in input().split(' ')])

print('Yes' if np.max(L) < np.sum(L) - np.max(L) else 'No')