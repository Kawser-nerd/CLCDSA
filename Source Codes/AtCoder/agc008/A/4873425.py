x,y = map(int,input().split())
if x == 0 and y > 0:
    print(y-x)
elif x == 0 and y < 0:
    print(1+abs(x+y))
elif y == 0 and x > 0:
    print(1+abs(x+y))
elif y == 0 and x < 0:
    print(y-x)
elif x < 0 and y < x:
    print(2+abs(x-y))
elif 0 < x and x < y:
    print(y-x)
elif 0 < y and x > y:
    print(2+abs(x-y))
elif 0 > y and x > y:
    print(abs(y+x)+1)
elif x < 0 and y > 0:
    print(abs(y+x)+1)
elif y < 0 and x < y:
    print(y-x)