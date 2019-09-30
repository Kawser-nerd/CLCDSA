a, b, x = map(int, input().split(' '))
if a % x == 0:
    print(b//x - a//x + 1)
else:
    print(b//x - a//x)