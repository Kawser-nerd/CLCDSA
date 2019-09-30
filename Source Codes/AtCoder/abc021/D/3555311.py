n = int(input())
k = int(input())
mod =  1000000007
fact = [1]*(n+k+1)
rfact = [1]*(n+k+1)
for i in range(n+k):
    fact[i+1] = rr = ((i+1) * fact[i]) % mod
    rfact[i+1] = pow(rr, mod-2, mod)
def comb(N, K,mod):
    return fact[N] * rfact[K] * rfact[N-K] % mod
print(comb(n+k-1,k,mod))