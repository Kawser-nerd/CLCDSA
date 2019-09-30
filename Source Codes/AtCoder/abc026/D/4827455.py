from math import sin, pi

a, b, c = map(int, input().split())

L = 0.0
H = 10000.0

while 1:
    M = (H + L) / 2
    f = a * M + b * sin(c * M * pi)
    if 99.999999 < f < 100.000001:
        print(M)
        exit()
    elif f < 100.0:
        L = M
    else:
        H = M

print(L)