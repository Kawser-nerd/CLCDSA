def dsum(n):
    ret = 0
    while n > 0:
        ret += n % 10
        n //= 10
    return ret

n = int(input())
s = "9" * len(str(n))
ans = 0
for i in range(len(str(n))):
    for x in range(10):
        a = s[:i] + str(x) + s[i+1:]
        if int(a) <= n:
            ans = max(ans, dsum(int(a)))
print(ans)