n = int(input())
a, b = n // 10, n % 10
print(100 * a + min(15*b, 100))