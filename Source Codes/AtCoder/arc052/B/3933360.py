import numpy as np
def inpl(): return map(int, input().split())

N, Q = inpl()
X = np.zeros(N)
R = np.zeros(N)
H = np.zeros(N)

for i in range(N):
    X[i], R[i], H[i] = inpl()

for _ in range(Q):
    a, b = inpl()
    ha = np.maximum(X + H - np.maximum(X, a), 0)
    ra = R / H * ha
    hb = np.maximum(X + H - np.maximum(X, b), 0)
    rb = R / H * hb
    print(np.sum(np.pi * ra**2 * ha / 3 - np.pi * rb**2 * hb / 3))