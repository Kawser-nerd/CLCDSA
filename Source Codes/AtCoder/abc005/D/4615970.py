def get_sum_rect(x_ul, y_ul, x_dr, y_dr):
    s = d[x_dr][y_dr] 
    if x_ul > 0:
        s -= d[x_ul - 1][y_dr]
    if y_ul > 0:
        s -= d[x_dr][y_ul - 1]
    if x_ul > 0 and y_ul > 0:
        s += d[x_ul - 1][y_ul - 1]
    return s

def get_max_rect(x, y):
    s_max = 0
    for i in range(n - x + 1):
        for j in range(n - y + 1):
            s = get_sum_rect(i, j, i + x - 1, j + y - 1)
            if s > s_max:
                s_max = s
    return s_max

n = int(input())

d = [[] for i in range(n)]
for i in range(n):
    d[i] = list(map(int, input().split()))

q = int(input())

p = [[] for i in range(q)]
for i in range(q):
    p[i] = int(input())

for i in range(n):
    for j in range(n):
        if i != 0:
            d[i][j] += d[i - 1][j]

for i in range(n):
    for j in range(n):
        if j != 0:
            d[i][j] += d[i][j - 1]

d_max = [0 for i in range(n * n + 1)]

for i in range(1, n * n + 1):
    s_max = d_max[i - 1]
    for j in range(1, n + 1):
        if i % j == 0 and i // j <= n:
            s = get_max_rect(i // j, j)
            if s > s_max:
                s_max = s
    d_max[i] = s_max

for i in range(q):
    print(d_max[p[i]])