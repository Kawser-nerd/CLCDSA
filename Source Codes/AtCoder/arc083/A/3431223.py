a, b, c, d, e, f = map(int, input().split())
x = set()
y = set()
for A in range(0, f + 1, 100 * a):
    for B in range(0, f + 1, 100 * b):
        if A + B > f:
            break
        if A + B:
            x.add(A + B)
for C in range(0, f + 1, c):
    for D in range(0, f + 1, d):
        if C + D > f:
            break
        y.add(C + D)
ans = 0
w = 100 * a
s = 0
for X in x:
    for Y in y:
        if X + Y <= f and 100 * Y / X <= e:
                if ans < Y / (X + Y):
                    ans = Y / (X + Y)
                    w = X
                    s = Y
print(w + s, s)