def ss(n):
    return n / s(n)
def s(n):
    return sum([int(a) for a in str(n)])

K = int(input())
n = 0
d = 1
while K > 0:
    t1=ss(n+d)
    t2=ss(n+10*d)
    if t1 > t2:
        d *= 10
    n += d
    print(n)
    K -= 1