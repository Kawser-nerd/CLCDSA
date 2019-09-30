n, x = map(int, input().split())
if (x > n // 2 and n % 2 == 0) or (x > (n + 1) // 2 and n % 2 == 1):
    x = n - x

A = n - x
B = x
k = 0
m = -1
ans = n
while m != 0:
    k = A // B
    m = A % B
    ans += B * k * 2
    if m == 0:
        ans -= B
    A = B
    B = m

print(ans)