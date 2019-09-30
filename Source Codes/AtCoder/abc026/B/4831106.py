import math
math.pi
n=int(input())
x=[]
Z=0
for i in range(n):
    x.append(int(input()))
x.sort(reverse=True)
for i in range(n):
    if i%2==0:
        Z+=x[i]**2
    elif i%2!=0:
        Z+=-x[i]**2
print(Z*math.pi)