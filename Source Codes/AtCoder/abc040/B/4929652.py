import math
n = int(input())
ans = 10**9
for i in range(1,math.floor(math.sqrt(n))+1):
    ans = min(ans, n - i * (n // i) + abs(i - (n // i)))
print(ans)