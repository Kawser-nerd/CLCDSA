from math import pi,atan2
q = 2*pi
def deg(a,b):
    d = b-a
    t = atan2(d.real, d.imag)
    if t<0: t += q
    return t
n = int(input())
cs = []
for _ in range(n):
    a,b = map(int,input().split())
    cs += [complex(a,b)]
for i in range(n):
    args = [deg(cs[i],cs[j])/q for j in range(n) if j!=i]
    args = sorted(args)
    dif = [args[i]-args[i-1] for i in range(n-1)]
    dif[0] += 1
    print(max(max(dif) - 1/2, 0))