n = int(input())

m = int(n ** 0.5)

ans = n ** 2

for i in range(1, m+1):
    temp = (n // i) - i + n % i
    ans = min(temp, ans)

print(ans)