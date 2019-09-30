import numpy as np
N = int(input())
T = list(map(int, input().split()))
V = list(map(int, input().split()))
T = [0, 0] + T + [0]
V = [0] + V + [0]
accT = np.cumsum(T)
INF = 10 ** 9

t2_max = accT[-1] * 2
speeds = np.ones(t2_max + 1) * INF
for t0, t1, v in zip(accT[:-1], accT[1:], V):
    sptmp = np.ones(t2_max + 1) * v
    sptmp[:t0 * 2] += np.arange(t0, 0, -0.5)
    sptmp[t1 * 2:] += np.arange(0, accT[-1] - t1 + 0.5, 0.5)
    speeds = np.minimum(speeds, sptmp)

ans = sum(speeds) / 2

print(ans)