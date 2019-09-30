a, b = map(int, input().split())

if a > b:
    a, b = b, a

count = 0

while abs(b - a) >= 8:
    a += 10
    count += 1

if a > b:
    a, b = b, a

if abs(b - a) > 3:
    a += 5
    count += 1

count += abs(b - a)
print(count)