from fractions import gcd
n, m = map(int, input().split())
s = input()
t = input()
g = gcd(n, m)
for i in range(g):
    if s[n // g * i] != t[m // g * i]:
        print(-1)
        break
else:
    print(n * m // g)