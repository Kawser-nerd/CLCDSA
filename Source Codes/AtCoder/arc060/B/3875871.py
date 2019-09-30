from math import sqrt

n = int(input())
s = int(input())

#n?b???????????
def f(b, n):
    res = 0
    while n:
        res += n % b
        n //= b
    return res
    
# s = n
if s == n:
    print(n+1)
    exit()

 
# 2 <= b <= sqrt(n)
for b in range(2, int(sqrt(n))+1):
    if f(b, n) == s:
        print(b)
        exit()
 
# sqrt(n) <= b <= n
for p in range(int(sqrt(n)), 0, -1):
    if (n - s) % p > 0:
        continue
    b = (n - s) // p + 1
    if b*b <= n:
        continue
    if f(b, n) == s:
        print(b)
        exit()
print(-1)