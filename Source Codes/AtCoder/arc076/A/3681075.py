import math
n,m = list(map(int, input().split()))
n, m = max(n,m), min(n, m)

if n - m > 1:
    ans = 0
elif n - m == 1:
    k = math.factorial(m) % (10**9 + 7)
    ans = k*k*n % (10**9 + 7)
else:
    k = math.factorial(m) % (10**9 + 7)
    ans = k*k*2 % (10**9 + 7)
print(ans)