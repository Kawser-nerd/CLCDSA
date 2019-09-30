x,y=map(int,input().split())
z=abs(abs(x)-abs(y))
if z==0:print(1)
elif abs(x)>abs(y):
    if x>0 and y>0:print(z+2)
    elif (x==0 and y>0) or (x<0 and y==0) or (x<0 and y<0):print(z)
    else:print(z+1)
else:
    if x<0 and y<0:print(z+2)
    elif (x==0 and y>0) or (x<0 and y==0) or (x>0 and y>0):print(z)
    else:print(z+1)