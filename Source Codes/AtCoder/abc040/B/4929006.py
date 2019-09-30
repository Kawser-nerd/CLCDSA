from math import sqrt
n = int(input())
ans = 10**9
for i in range(1,int(sqrt(n))+1):
    ans = min(ans, n - i * (n // i) + abs(i - (n // i)))
print(ans)