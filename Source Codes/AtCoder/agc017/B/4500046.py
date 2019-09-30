n, a, b, c, d = map(int, input().split())
if a > b:
    a, b = b, a

for k in range(n):
    if a + k * c - (n - k - 1) * d <= b <= a + k * d - (n - k - 1) * c:
        print("YES")
        exit()

print("NO")