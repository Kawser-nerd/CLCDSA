from math import log
p = float(input())
a = 2*p*log(0.5)/3
x = max(0,(3*log(-1.0/a,0.5))/2)
print(x+p/(2**(2*x/3)))