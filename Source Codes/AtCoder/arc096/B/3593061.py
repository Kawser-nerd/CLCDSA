def inpl(): return [int(i) for i in input().split()]
import numpy as np
N, C = inpl()

x, v = np.array([inpl() for _ in range(N)]).T

cwo = np.cumsum(v)-x
cwr = np.hstack(([0], cwo-x))
cwo = np.hstack(([0], cwo))
for i in range(N):
    cwr[i+1] = max(cwr[i], cwr[i+1])
av = v[::-1]
ax = C - x[::-1]

acwo = np.cumsum(av)-ax
acwr = np.hstack(([0], acwo-ax))
acwo = np.hstack(([0], acwo))
for i in range(N):
    acwr[i+1] = max(acwr[i], acwr[i+1])

ans1 = cwo + acwr[::-1]
ans2 = acwo + cwr[::-1]
print(max(np.max(ans1), np.max(ans2), 0))