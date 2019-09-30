a, b, c, d = map(int, input().split())
x = b / a
y = d / c
print("TAKAHASHI" if x > y else "DRAW" if x == y else "AOKI")