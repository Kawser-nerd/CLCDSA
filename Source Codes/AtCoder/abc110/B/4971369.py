n, m, x, y = map(int, input().split())
x_want = list(int(i) for i in input().split())
y_want = list(int(i) for i in input().split())

z = 100
z = max(x_want) + 1

if (x < z and z <= y) and (max(x_want) < z) and (min(y_want) >= z):
    print('No War')
else:
    print('War')