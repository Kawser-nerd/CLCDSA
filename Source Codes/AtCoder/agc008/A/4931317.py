x, y = map(int, input().split())

if abs(x) == abs(y):
    print(1)
elif abs(x) < abs(y):
    if y > 0:
        if x >= 0:
            print(abs(y) - abs(x))
        else:
            print(abs(y) - abs(x) + 1)
    else:
        if x >= 0:
            print(abs(y) - abs(x) + 1)
        else:
            print(abs(y) - abs(x) + 2)
else:
    if x < 0:
        if y <= 0:
            print(abs(x) - abs(y))
        else:
            print(abs(x) - abs(y) + 1)
    else:
        if y <= 0:
            print(abs(x) - abs(y) + 1)
        else:
            print(abs(x) - abs(y) + 2)