import math
import sys
N = int(input())
if N == 1:
    print(0)
    sys.exit()
c, s, f = [0]*(N-1),[0]*(N-1),[0]*(N-1)
for i in range(N-1):
    c[i], s[i], f[i] = map(int, input().split())
for i in range(N):
    cur = 0
    for j in range(i, N-1):
        if cur <= s[j]:
            cur = s[j] + c[j]
        else:
            cur += (s[j]+f[j]*math.ceil((cur-s[j])/f[j])-cur) + c[j]
    print(cur)