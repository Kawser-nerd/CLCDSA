x,y = map(int,input().split())
kyori = abs(abs(x) - abs(y))

hanten = 0
if (x>0 and y>0 or x<0 and y<0) and y<x:
    hanten = 2
if x>0 and y<0 or x<0 and y>0:
    hanten = 1
if (x==0 or y==0) and y < x:
    hanten = 1

print(kyori + hanten)