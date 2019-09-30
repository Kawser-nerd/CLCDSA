from math import log
p=float(input())
t=-1.5*(log(1.5/(p*log(2))))/log(2)
if t>0:
    print(t+p/(2**(t/1.5)))
else:
    print(p)