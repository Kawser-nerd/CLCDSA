n, m = map(int, input().split())
b = [list(map(int, list(input()))) for i in range(n)]
a = [[0]*m for i in range(n)]

for i in range(1, n-1):
    for j in range(1, m-1):
        x = min(b[i+1][j], b[i-1][j], b[i][j+1], b[i][j-1])
        a[i][j] += x
        b[i+1][j] -= x;b[i-1][j] -= x;b[i][j+1] -= x;b[i][j-1] -= x

for i in a:
    print("".join(map(str, i)))