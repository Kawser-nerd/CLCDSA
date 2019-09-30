a,b = map(int,input().split())
a = abs(a)
b = abs(b)
if a == b:
    print('Draw')
elif a > b:
    print('Bug')
else:
    print('Ant')