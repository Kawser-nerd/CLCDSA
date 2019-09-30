def gcd(a, b):
    if b == 0:return a
    return gcd(b, a % b)

t = int(input())
for _ in range(t):
    a, b, c, d = map(int, input().split())
    #exception
    if a < b or d < b:
        print("No")
        continue

    if c >= b:
        print("Yes")
        continue

    g = gcd(d, b)
    print("Yes" if b - g + a % g <= c else "No")