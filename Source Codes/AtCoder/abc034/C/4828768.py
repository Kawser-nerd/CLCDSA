W, H = map(int, input().split())

def mod_pow(a, b, m):
    '''
     return (a**b%m)
    '''
    r = 1
    while b > 0:
        if b & 1:
            r = r * a % m
        a = a * a % m
        b >>= 1
    return r

def mod_inv(a, m):
    '''
     return ((a**(-1))%m)
    '''
    return mod_pow(a, m-2, m)

from math import factorial as f
m = 10**9+7
ret = (f(W+H-2) % m) * (mod_inv(f(W-1)*f(H-1), m)) % m
print(ret)