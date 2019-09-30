H, W = map(int, input().split())
Q = [list(map(int, input().split())) for i in range(int(input()))]

K = 2*H
rK = range(K)
I = [+(i//K == i%K) for i in range(K*K)]
B = (2, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0) if H == 2 else (1, 1, 1, 0)
MOD = 10**9 + 7
if H == 2:
    def mul(A, B):
        a0,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15=A
        b0,b1,b2,b3,b4,b5,b6,b7,b8,b9,b10,b11,b12,b13,b14,b15=B
        return (a0*b0+a1*b4+a2*b8+a3*b12)%MOD,(a0*b1+a1*b5+a2*b9+a3*b13)%MOD,(a0*b2+a1*b6+a2*b10+a3*b14)%MOD,(a0*b3+a1*b7+a2*b11+a3*b15)%MOD,(a4*b0+a5*b4+a6*b8+a7*b12)%MOD,(a4*b1+a5*b5+a6*b9+a7*b13)%MOD,(a4*b2+a5*b6+a6*b10+a7*b14)%MOD,(a4*b3+a5*b7+a6*b11+a7*b15)%MOD,(a8*b0+a9*b4+a10*b8+a11*b12)%MOD,(a8*b1+a9*b5+a10*b9+a11*b13)%MOD,(a8*b2+a9*b6+a10*b10+a11*b14)%MOD,(a8*b3+a9*b7+a10*b11+a11*b15)%MOD,(a12*b0+a13*b4+a14*b8+a15*b12)%MOD,(a12*b1+a13*b5+a14*b9+a15*b13)%MOD,(a12*b2+a13*b6+a14*b10+a15*b14)%MOD,(a12*b3+a13*b7+a14*b11+a15*b15)%MOD
else:
    def mul(A, B):
        a0,a1,a2,a3=A
        b0,b1,b2,b3=B
        return (a0*b0+a1*b2)%MOD,(a0*b1+a1*b3)%MOD,(a2*b0+a3*b2)%MOD,(a2*b1+a3*b3)%MOD
PM = [0]*40
PM[0] = I
PM[1] = B

C = B
for i in range(2, 40):
    PM[i] = C = mul(C, C)

def Bpow(k):
    R = I
    i = 1
    while k:
        if k & 1: R = mul(R, PM[i])
        k >>= 1; i += 1
    return R

mp = {t: i for i, t in enumerate(sorted({t for s, t in Q}))}
L = len(mp)
bits = [0]*L
BS = [0]*L; FS = [0]*L
L2 = 2**((L-1).bit_length())
data = [None]*(L2*2)
prev = 0
for t, i in sorted(mp.items()):
    BS[i] = Bpow(t-prev-1)
    data[L2-1+i] = FS[i] = mul(BS[i], B)
    prev = t
F = Bpow(W+1-prev)
for k in range(L2-2, -1, -1):
    if data[2*k+2] is None:
        data[k] = data[2*k+1]
    else:
        data[k] = mul(data[2*k+2], data[2*k+1])

def update(k, X):
    k += L2-1
    data[k] = X
    while k:
        k = (k-1) // 2
        if data[2*k+2] is None:
            data[k] = data[2*k+1]
        else:
            data[k] = mul(data[2*k+2], data[2*k+1])
    return data[0]

def solve():
    if H == 1:
        for s, t in Q:
            k = mp[t]
            bits[k] ^= 1
            b = bits[k]
            if b == 0:
                M = FS[k]
            else:
                M = mul((0, 0, 1, 1), BS[k])
            R = update(k, M)
            v = mul(F, R)
            yield v[1]
    elif H == 2:
        for s, t in Q:
            k = mp[t]
            bits[k] ^= s
            b = bits[k]
            if b == 0:
                M = FS[k]
            else:
                if b == 1:
                    M = (0, 0, 0, 0, 2, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0)
                elif b == 2:
                    M = (0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 0, 1, 0)
                elif b == 3:
                    M = (0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1)
                M = mul(M, BS[k])
            R = update(k, M)
            v = mul(F, R)
            yield v[3]
print(*solve(), sep='\n')