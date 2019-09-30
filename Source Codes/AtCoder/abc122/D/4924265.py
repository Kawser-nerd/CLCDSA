import sys

import numpy as np

readInt = lambda: int(sys.stdin.readline())
readIntN = lambda: [int(v) for v in sys.stdin.readline().split(" ")]


n = readInt()
M = 10 ** 9 + 7


dp = np.zeros((n + 1, 256), dtype=np.uint32)
dp[0, 255] = 1


for i in range(n):
    for j4 in [0, 64, 128, 192]:
        for j3 in [0, 16, 32, 48]:
            j43 = j4 + j3
            for j2 in [0, 4, 8, 12]:
                j432 = j43 + j2
                for j1 in range(4):
                    j = j432 + j1
                    l321 = 4 * (j3 + j2 + j1)
                    for l0 in range(4):
                        if (6 == (j3 + 4 * j1 + l0)) or (6 == (j3 + j2 + l0)) or (6 == (4 * j2 + 4 * j1 + l0)) or (6 == (16 * j1 + j2 + l0)) or (6 == (4 * j2 + 4 * l0 + j1)):
                            continue
                        l = l321  + l0
                        dp[i + 1, l] = (dp[i + 1, l] + dp[i, j]) % M

ret = 0
for v in dp[-1]:
    ret = (ret + v) % M
print(ret)