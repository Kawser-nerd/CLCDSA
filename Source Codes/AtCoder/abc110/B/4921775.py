N, M, X, Y = map(int, input().split())
x = list(map(int, input().split())) + [X]
y = list(map(int, input().split())) + [Y]

if X < Y and  max(x) < min(y):
    f = True
else:
    f = False

if f:
    print('No War')
else:
    print('War')