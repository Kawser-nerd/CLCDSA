a,b=map(int,input().split())
x=a+b
y=a-b
z=a*b
if y<=x and z<=x:
    print(x)
elif x<=y and z<=y:
    print(y)
else:
    print(z)