def extgcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b//a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
        g = b
    return x, y, g


def modinv(a, m):
    x, y, g = extgcd(a, m)
    if g != 1:
        print ("[+]Inverse does not exist.")
    else:
        return ((m + x) % m) % m


def mod_comb(n, r, mod):
    ans_mul, ans_div = 1, 1

    for i in range(r):
        ans_mul *= (n-i)
        ans_div *= (i+1)
        ans_mul %= mod
        ans_div %= mod

    return ans_mul * modinv(ans_div, mod) % mod


def main():
    w, h = map(int, input().split())
    mod = int(10**9+7)

    print ( mod_comb(w+h-2, h-1, mod) )

main()