from decimal import Decimal
from decimal import getcontext

getcontext().prec = 56


def f(x, P):
    return Decimal(x) + P * Decimal(2**Decimal(Decimal(-1)*Decimal(x*Decimal(2/3))))


def solv(P):
    l = Decimal(0)
    r = Decimal(100)
    while True:
        ml = Decimal(l + (r-l)*Decimal(1 / 3))
        mr = Decimal(l + (r-l)*Decimal(2 / 3))
        if (mr - ml) < 0.000000001:
            return f(mr, P)
        fml = f(ml, P)
        fmr = f(mr, P)
        if fml < fmr:
            r = mr
        elif fml > fmr:
            l = ml
        else:
            l = ml
            r = mr


I = input().split(".")
I[1] = "." + I[1]
P = Decimal(I[0]) + Decimal(I[1])
print(solv(P))