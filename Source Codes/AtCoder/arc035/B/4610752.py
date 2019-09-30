import math
import collections
d=1
e=0
f=0
t=[0]*10001
for i in range(int(input())):
    t[int(input())]+=1
for i in range(1,10001):
    s=t[i]
    if s>0:
        d*=math.factorial(s)
        e+=i*(s*(s+1)//2)+f*s
        f+=i*s
print(e)
print(d%(10**9+7))