A,B,C = [int(input()) for i in range(3)]

MOD = 10**9+7

def mul(a,b):
    return (a*b) % MOD

def pow(a,n): # a^n
    ret = 1
    mag = a
    while n > 0:
        if n & 1:
            ret = mul(ret, mag)
        mag = mul(mag, mag)
        n >>= 1
    return ret

def inv(a):
    return pow(a, MOD-2)

xn = mul(B,C) - mul(A,C)
xd = mul(A,B) - mul(B,C) + mul(A,C)
x = mul(xn, inv(xd))

yn = mul(B,C) - mul(A,B)
yd = mul(A,C) - mul(B,C) + mul(A,B)
y = mul(yn, inv(yd))

print(x,y)