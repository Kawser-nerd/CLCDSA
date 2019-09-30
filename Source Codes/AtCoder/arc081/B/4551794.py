# python template for atcoder1
import sys
sys.setrecursionlimit(10**9)
N = int(input())
s = input()
t = input()
X = True
Y = False
MOD = 10**9+7
if s[0] == t[0]:
    i = 1
    ans = 3
    prev = X
else:
    i = 2
    ans = 6
    prev = Y
while i < N:
    if s[i] == t[i]:
        if prev:
            ans = (ans*2) % MOD
        else:
            ans = ans % MOD
        i += 1
        prev = X
    else:
        if prev:
            ans = (ans*2) % MOD
        else:
            ans = (ans*3) % MOD
        i += 2
        prev = Y
print(ans)