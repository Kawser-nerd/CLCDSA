P = float(input())

def f(p):
    return p + P*2**(-p/1.5)

EPSILON = 10**(-9)
lo = 0
hi = P
while hi-lo >= 10**(-8):
    m = (hi + lo) /2
    fm = f(m)
    fme = f(m+EPSILON)
    if fm > fme:
        lo = m
    else:
        hi = m
print(min(f(lo), f(hi)))