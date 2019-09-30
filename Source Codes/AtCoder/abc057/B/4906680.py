import sys

ni = lambda: int(sys.stdin.readline().rstrip())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())
INF = 10 ** 9
n, m = nm()
ab = [nl() for i in range(n)]
cd = [nl() for i in range(m)]
ans = []
for i in range(n):
    temp = INF
    a = ab[i][0]
    b = ab[i][1]
    for j in range(m-1, -1, -1):
        c = cd[j][0]
        d = cd[j][1]
        if abs(a - c) + abs(b - d) <= temp:
            temp = abs(a - c) + abs(b - d)
            idx = j + 1
    ans.append(str(idx))
print('\n'.join(ans))