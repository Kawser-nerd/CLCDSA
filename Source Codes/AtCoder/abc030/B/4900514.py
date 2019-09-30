n,m=map(int,input().split())
a=30*n+0.5*m
b=6*m
c=abs(a-b)
if c<=180:
    print(c)
elif c>=360 and c<540:
    print(c-360)
elif c>=540:
    print(720-c)
else:
    print(360-c)