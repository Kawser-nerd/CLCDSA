N = int(input())
res = []
for i in range(N):
    X, Y, Z = map(int, input().split())
    LX = X-1; RX = 0
    LY = Y-1; RY = 0
    LZ = Z-1; RZ = 0
    M = int(input())
    for j in range(M):
        x, y, z = map(int, input().split())
        LX = min(LX, x); RX = max(RX, x)
        LY = min(LY, y); RY = max(RY, y)
        LZ = min(LZ, z); RZ = max(RZ, z)
    res += LX, LY, LZ, X-1-RX, Y-1-RY, Z-1-RZ
ans = 0
for e in res:
    ans ^= e
print('WIN' if ans else 'LOSE')