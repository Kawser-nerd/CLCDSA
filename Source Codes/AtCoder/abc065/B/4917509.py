import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

n = ni()

a = [ni() for _ in range(n)]
count = 0
nexti = 0
for i in range(n):
    if nexti == 1:
        print(count)
        exit()
    else:
        nexti = a[nexti] - 1
        count += 1
print(-1)