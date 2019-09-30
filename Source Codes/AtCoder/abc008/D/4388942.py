#A
"""
s, t = map(int, input().split())
print(t-s+1)
"""

#B
"""
n = int(input())
s = {}
for i in range(n):
    si = input()
    if not si in s:
        s[si] = 1
    else:
        s[si] += 1
s = sorted(s.items(), key=lambda x: x[1], reverse=True)

print(s[0][0])
"""

#C
"""
import math
fact = [math.factorial(n) for n in range(101)]
n = int(input())
c = [int(input()) for i in range(n)]
yakusu = [-1 for i in range(n)]
for i in range(n):
    for k in range(n):
        if c[i] % c[k] == 0:
            yakusu[i] += 1
ans = 0
omote = [0 for i in range(n)]
for i in range(n):
    for k in range(i // 2 + 1):
        omote[i] += fact[n] / fact[i + 1] / fact[n - i - 1] * fact[n - i - 1] * fact[i] 
for i in yakusu:
    ans += omote[i]
print(ans / fact[n])
"""

#D

w, h = map(int, input().split())
n = int(input())
xy = [list(map(int, input().split())) for _ in range(n)]

#?????
field = [[[[0 for i in range(n)] for k in range(n)] for l in range(n)] for j in range(n)]
"""
def dp(xle, ydo, xri, yup):
    if (xle, ydo, xri, yup) in d:
        return d[(xle, ydo, xri, yup)]
    
    bf = 0
    for x, y in xy:
        if xle <= x <= xri and ydo <= y <= yup:
            bf = max(bf, xri - xle + yup - ydo + 1 + dp(x + 1, y + 1, xri, yup) + dp(xle, y + 1, x - 1, yup) + dp(xle, ydo, x - 1, y - 1) + dp(x + 1, ydo, xri, y - 1))
    d[(xle, ydo, xri, yup)] = bf
    return bf
"""
#???

d = {}

def dp(xle, ydo, xri, yup):
    if (xle, ydo, xri, yup) in d:
        return d[(xle, ydo, xri, yup)]
    
    bf = 0
    for x, y in xy:
        if xle <= x <= xri and ydo <= y <= yup:
            bf = max(bf, xri - xle + yup - ydo + 1 + dp(x + 1, y + 1, xri, yup) + dp(xle, y + 1, x - 1, yup) + dp(xle, ydo, x - 1, y - 1) + dp(x + 1, ydo, xri, y - 1))
    d[(xle, ydo, xri, yup)] = bf
    return bf



print(dp(1,1,w,h))