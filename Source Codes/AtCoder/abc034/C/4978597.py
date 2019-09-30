def mod_Combination(n, k, mod):
    def ext_gcd(a, b):
        if b == 0:return a, 1, 0
        else:d,x,y = ext_gcd(b,a%b);x-=(a//b)*y 
        return d,y,x
    p,q=1,1
    for i in range(n-k+1, n+1):
        p=(p*i)%mod
    for i in range(2, k+1):
        q=(q*i)%mod
    return int(p*(ext_gcd(q, mod)[1]%mod)%mod)
 
x, y = map(int, input().split())
print(mod_Combination(x + y - 2, x - 1, 10**9 + 7))