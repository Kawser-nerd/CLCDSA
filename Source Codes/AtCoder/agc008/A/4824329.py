x, y = map(int, input().split())
if 0 <= x <= y or x <= y <= 0:
    print(y - x)
elif x <= 0 <= y or y <= 0 <= x:
    print(abs(abs(y) - abs(x)) + 1)
else:
    print(abs(abs(y) - abs(x)) + 2)