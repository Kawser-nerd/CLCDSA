N = int(input())
r = input()

total = 0
for c in r:
    x = "FDCBA".find(c)
    total += x

result = total / N

print(result)