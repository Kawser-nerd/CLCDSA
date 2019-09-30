a,b = map(int,input().split(' '))
if a < 0 and 0 < b:
    print(b - a - 1)
else:
    print(b - a)