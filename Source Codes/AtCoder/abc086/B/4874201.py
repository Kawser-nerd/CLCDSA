a, b = input().split()

x = int(a + b)

print("Yes" if x == int(x ** 0.5) ** 2 else "No")