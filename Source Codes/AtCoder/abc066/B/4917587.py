import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

s = ns()
n = len(s)
for i in range(n):
    s = s[:-1]
    if len(s) % 2 == 0:
        m = len(s) // 2
        count = 0
        for j in range(m):
            if s[j] == s[j + m]:
                count += 1
        if count == m:
            print(2 * m)
            exit()