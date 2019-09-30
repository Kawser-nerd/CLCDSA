iipt=lambda:int(input())
miipt=lambda:list(map(int,input().split(" ")))
import math
R,B=miipt()
x,y=miipt()
a=0
b=min(R,B)+1
while b-a>1:
    c=(a+b)//2
    if c<=(R-c)//(x-1)+(B-c)//(y-1):
        a=c
    else:
        b=c
print(a)