import math
n = int(input())
m = math.floor(math.sqrt(n))
ans = 100000
for i in range(1, m + 1):
    for j in range(1, n//i + 1):
        ans = min(abs(i - j) + (n - i*j), ans)
print(ans)