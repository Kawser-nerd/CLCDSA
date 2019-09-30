MOD = 10**9+7
    
def comb(a:int, b:int):
    if b > a-b: return comb(a, a-b)
    mul = 1
    div = 1
    for i in range(b):
        mul *= a-i
        div *= i+1
        mul %= MOD
        div %= MOD
        
    ret = mul * pow(div, MOD-2, MOD)
    return ret

if __name__ == '__main__':
    N,M = map(int, input().split())
    ans = 1
    
    #  ?????
    i=2
    nokori = M
    while i*i <= nokori:
        if nokori%i==0:
            cnt = 0
            while nokori%i==0:
                cnt += 1
                nokori //= i
            ans *= comb(N+cnt-1, N-1)
            ans %= MOD
        i += 1
            
    if nokori != 1:
        ans *= comb(N+1-1, N-1)
        ans %= MOD
        
    print(ans)