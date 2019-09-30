import math
a,b,c=map(int,input().split())
def f(x):
    return a*x+b*math.sin(c*x*math.pi)
l=10000
r=0
while abs(f(r)-100)>10**(-6):
    s=(l+r)/2
    if f(s)<=100:
        r=s
    else:
        l=s
print(r)