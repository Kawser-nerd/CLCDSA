def inpl(): return [int(i) for i in input().split()]
import numpy as np

N, K = inpl()
H = np.zeros((K,K), dtype = np.int32)
for _ in range(N):
    x, y, c = input().split() 
    x = int(x)
    y = int(y)
    t = c == 'B'
    x %= 2*K
    y %= 2*K
    if x >= K:
        x -= K
        t = not t
    if y >= K:
        y -= K
        t = not t
    if t:
        H[x][y] += 1
        continue
    H[x][y] -= 1

H = H.cumsum(axis=0)
H = H.cumsum(axis=1)

checkH = H[K-1][K-1] + 2*H
for i in range(K):
            checkH[i] -= H[i][K-1]
            checkH.T[i] -= H.T[i][K-1]

Hans = (N - checkH[K-1][K-1])//2 + checkH

print(max(np.amax(Hans), N-np.amin(Hans)))