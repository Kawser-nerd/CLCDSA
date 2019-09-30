A,B,C = map(int,input().split())
import numpy as np
def f(t):
    return A*t+B*np.sin(C*t*np.pi)

suplim = 10000
inflim = 0

def bisection(sup,inf):
    mid = (sup+inf)/2
    if f(mid) > 100:
        sup = mid
    else:
        inf = mid
    return sup,inf


while abs(f((suplim+inflim)/2) - 100) > 10 ** (-10):
    suplim , inflim = bisection(suplim,inflim)

print(suplim)