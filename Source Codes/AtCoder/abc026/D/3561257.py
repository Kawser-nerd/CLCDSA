import math
A,B,C=map(int,input().split())

MIN=(100-B)/A
MAX=(100+B)/A

while True:
    t=(MIN+MAX)/2
    ANS=A*t+B*math.sin(C*t*math.pi)
    if abs(100-ANS)<10**(-6):
        break
    elif ANS>100:
        MAX=t
    else:
        MIN=t

print(t)