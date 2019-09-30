MOD = 10**9 + 7
def comb_fermat(n:int, r:int)->int:
    # return nCr (mod MOD)
    if r > n-r: return comb_fermat(n, n-r)
    mul,div = 1,1
    for i in range(r):
        mul *= n-i
        mul %= MOD
        div *= i+1
        div %= MOD

    ret = mul * pow(div, MOD-2, MOD) % MOD
    return ret

n = int(input())
r = int(input())
print(comb_fermat(n+r-1,n-1))