A, B, C, X, Y = map(int, input().split())
mi = A * X + B * Y
mi = min(mi, C * 2 * min(X, Y) + (X-min(X, Y)) * A + (Y-min(X, Y)) * B)
mi = min(mi, C * 2 * max(X, Y))
print(mi)