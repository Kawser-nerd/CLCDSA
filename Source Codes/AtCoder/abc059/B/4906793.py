import sys
ns = lambda: sys.stdin.readline().rstrip()
ni = lambda: int(ns())
nm = lambda: map(int, sys.stdin.readline().split())
nl = lambda: list(nm())

a = list(ns())
b = list(ns())

if len(a) > len(b):
    print('GREATER')
elif len(a) < len(b):
    print('LESS')
else:
    for i in range(len(a)):
        if a[i] > b[i]:
            print('GREATER')
            exit()
        elif a[i] < b[i]:
            print('LESS')
            exit()
    print('EQUAL')