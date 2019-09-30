import sys

def chk1(t, x, y):
    return t % 2 == (x + y) % 2
def chk2(t, x, y):
    return t >= abs(x) + abs(y)
def chk(t, x, y):
    return chk1(t, x, y) and chk2(t, x, y)

N = int(input())
T = [0] * (N + 1)
X = [0] * (N + 1)
Y = [0] * (N + 1)
for i in range(1, N + 1):
    T[i], X[i], Y[i] = map(int, input().split())
for i in range(1, N + 1):
    dt, dx, dy = T[i] - T[i - 1], X[i] - X[i - 1], Y[i] - Y[i - 1]
    if not chk(dt, dx, dy):
        print('No')
        sys.exit(0)
print('Yes')