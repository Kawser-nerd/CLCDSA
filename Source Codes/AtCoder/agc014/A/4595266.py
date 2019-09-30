def rec(x, y, z):
    if (x | y | z) & 1:
        return 0

    if x == y == z:
        return -INF

    nx = (y + z) >> 1
    ny = (z + x) >> 1
    nz = (x + y) >> 1
    return rec(nx, ny, nz) + 1


INF = float('inf')
A, B, C = map(int, input().split())
ans = rec(A, B, C)
print(ans if ans >= 0 else -1)

'''
???????????????????
?????????????a==b==c??????
'''