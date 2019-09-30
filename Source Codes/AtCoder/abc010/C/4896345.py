*t, T, V = map(int, input().split())
n = int(input())
x, y = [0] * n, [0] * n
for i in range(n):
    x[i], y[i] = map(int, input().split())

def distance(x1, y1, x2, y2):
    ans = (((x2 - x1) ** 2) + ((y2 - y1) ** 2)) ** (1 / 2)
    return ans
d = distance(t[0], t[1], t[2], t[3])

i = 0
while i < n:
    if distance(t[0], t[1], x[i], y[i]) + distance(t[2], t[3], x[i], y[i]) <= T * V:
        print('YES')
        break
    else:
        i += 1
if i == n:
    print('NO')