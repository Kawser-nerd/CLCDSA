def gcd(a, b):
    while b:
        a, b = b, a % b
    return a

a, b, c = map(int, input().split())
x = gcd(a, b)

print("YES" if c % x == 0 else "NO")