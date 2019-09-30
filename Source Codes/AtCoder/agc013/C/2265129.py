N, L, T = map(int, input().split())

s = 0
X = [0] * N
for i in range(N):
    x, w = map(int, input().split())
    x += ((w + 1) % 3 - 1) * T
    # x?0?????????
    s += x // L
    X[i] = x % L

X.sort()
for i in range(N):
    print(X[(i+s) % N])