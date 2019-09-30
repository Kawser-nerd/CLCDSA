a = int(input())
b = a + 1

a = a * a
b = b * b - 1

while (a + 99) // 100 <= b // 100:
    a = (a + 99) // 100
    b //= 100
print(a)