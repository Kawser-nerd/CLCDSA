from math import sqrt
n, s = int(input()), int(input())

if n == s:
    print(n+1)
    exit()

def check(b, n):
    result = 0
    while n:
        result += n % b
        n //= b
    return result

sq_n = int(sqrt(n))

for b in range(2, sq_n+1):
    if check(b, n) == s:
        print(b)
        exit()

if s == 1:
    print(n)
    exit()

ans = inf = float("inf")
for p, q in zip(range(1, min(sq_n, s)+1), range(s-1, -1, -1)):
    b = (n-q) // p
    if b > 1 and check(b, n) == s:
        ans = b

print(ans if ans < inf else -1)