import sys

N, M = map(int, input().rstrip().split())

if 4*N < M < 2*N:
    print(-1, -1, -1)
    sys.exit()

for t in range(N+1):
    x = 3*N - M + t
    y = M - 2*N - 2*t
    z = t
    if x >= 0 and y >= 0:
        break

if x >= 0 and y >= 0:
    print(x, y, z)
else:
    print(-1, -1, -1)