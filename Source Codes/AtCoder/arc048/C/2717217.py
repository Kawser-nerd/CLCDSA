# seishin.py
MOD = 10**9 + 7
N = int(input())
L = sorted(set([int(input()) for i in range(N)]))
N = len(L)

def gcd(m, n):
    r = m % n
    return gcd(n, r) if r else n

if N == 1:
    x = 0
else:
    x = L[1]-L[0]
    for i in range(2, N):
        x = gcd(x, L[i]-L[0])
print(pow(2, L[0]+(x+1)//2, MOD))