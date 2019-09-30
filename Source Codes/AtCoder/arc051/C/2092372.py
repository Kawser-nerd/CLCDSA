from math import log
def main():
    n,mul,b = map(int,input().split())
    a = list(map(int,input().split()))
    mod = 10**9+7
    a = sorted(a)
    if mul == 1:
        for i in a: print(i%mod)
        return 0

    while ( b > 0 and max(a) > min(a)*mul):
        a[a.index(min(a))] *= mul
        b -= 1
    a = sorted(a)
    for i in range(n):
        a[i] = (a[i] * pow(mul,b//n,mod)) % mod
    b -= b//n*n
    while (b > 0):
        a.append(a[0]*mul%mod)
        a.pop(0)
        b -= 1
    for i in range(n): print(a[i])
    return 0
main()