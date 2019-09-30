n = int(input())
k = int(input())
Mod = 10**9+7
def fact(l):
    res = 1
    for i in range(1,l+1):
        res *= i
        res %= Mod
    return res 
def factinv(l):
    res = 1
    for i in range(1,l+1):
        res *= pow(i,Mod-2,Mod)
        res %= Mod
    return res 
print(fact(n+k-1)*factinv(k)*factinv(n-1)%Mod)