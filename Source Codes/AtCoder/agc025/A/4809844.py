def dsum(n):
    ret = 0
    while n > 0:
        ret += n % 10
        n //= 10
    return ret
n = int(input())
ans = 10**7
for i in range(1, n//2+1):
    ans = min(ans, dsum(i) + dsum(n-i))
print(ans)