x,y = map(int,input().split())
a = abs(x)
b = abs(y)
if a == b:
    print(1)
elif y == 0:
    if x > 0:
        print(x+1)
    else:
        print(a)
elif x >= 0 and y >= 0:
    if x < y:
        print(y-x)
    else:
        print(a-b+2)
elif x >= 0 or y >= 0:
    print(abs(a-b)+1)
else:
    if a > b:
        print(a-b)
    else:
        print(b-a+2)