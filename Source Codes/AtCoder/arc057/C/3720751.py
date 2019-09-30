from decimal import *
S = input()
N = int(S)
sq = Decimal(N*N)
Q = str(sq)

cx = getcontext()
cx.prec = len(S)*2

p = 10**len(Q)
while p:
    a = (sq-1) // p + 1
    rt = cx.sqrt(a)
    rts = str(rt).replace('.','')
    if rts[:len(S)] == S:
        while a%100==0:
            a //= 100
        print(a)
        exit()
    if (len(rts) > 5 and rts[:5] == S[:5]):
        p //= 100
    else:
        p //= 10
assert False