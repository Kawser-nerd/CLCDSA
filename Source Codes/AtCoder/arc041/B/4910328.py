n, m = map(int, input().split())
b = [list(map(int,input())) for i in range(n)]
a = [[0]*m for i in range(n)]

for ni in range(n):
    for mi in range(m):
        if b[ni][mi] > 0:
            tmp = b[ni][mi]
            b[ni][mi] -= tmp
            b[ni+1][mi-1] -= tmp
            b[ni+1][mi+1] -= tmp
            b[ni+2][mi] -= tmp
            a[ni+1][mi] += tmp

for ni in range(n):
    for mi in range(m):
        print(a[ni][mi], end="")
    print()