import math
a,b,x=map(int,input().split())
if a%x>0 and b//x-a//x==0:
    print(0)
else:
    print((b//x)-math.ceil(a/x)+1)