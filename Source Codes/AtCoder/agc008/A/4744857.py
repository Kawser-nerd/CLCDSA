x,y = list(map(int,input().split()))
if 0<x and x<y:
    print(y-x)
elif x<0 and 0<y:
    if abs(x)>=abs(y):
        print(-x-y+1)
    else:
        print(x+y+1)
    
elif y <0 and 0<x:
    if abs(x)>=abs(y):
        print(x+y+1)
    else:
        print(-x-y+1)
elif 0 < y and y<x:
    print(x-y+2)
elif x<y and y<0:
    print(y-x)
elif y < x and x < 0:
    print(x-y+2)
elif x==0:
    if y > 0:
        print(y)
    else:
        print(-y+1)
        
else: #y==0
    if x > 0:
        print(x+1)
    else:
        print(-x)