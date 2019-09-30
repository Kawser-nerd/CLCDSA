R, B = map(int, input().split())
x, y = map(int, input().split())

a = 0
b = R + 1
while b - a > 1:
    c = (a + b) // 2
    if R - c < 0 or B - c < 0 or (R - c) // (x - 1) + (B - c) // (y - 1) < c:
        b = c
    else:
        a = c

print(a)