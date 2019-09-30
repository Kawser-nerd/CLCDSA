# -*- coding utf-8 -*-

w,h,n=map(int,input().split())
x,y=0,0

for i in range(n):
    a,b,c=map(int,input().split())
    if c==1:
        x=max(x,a)
    elif c==2:
        w=min(w,a)
    elif c==3:
        y=max(y,b)
    elif c==4:
        h=min(h,b)


print(max(0,w-x)*max(0,h-y))