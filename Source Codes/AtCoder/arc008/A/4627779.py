n = int(input())

a = n//10 * 100
b = (n % 10) * 15
b = min(b, 100)

print(a+b)