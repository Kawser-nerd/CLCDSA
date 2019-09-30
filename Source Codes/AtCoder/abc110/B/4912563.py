import sys

N, M, X, Y = map(int, input().split())
xx = list(map(int, input().split()))
yy = list(map(int, input().split()))

for z in range(X+1, Y+1):
    if all(x < z for x in xx) and all(y >= z for y in yy):
        print('No War')
        sys.exit()

print('War')