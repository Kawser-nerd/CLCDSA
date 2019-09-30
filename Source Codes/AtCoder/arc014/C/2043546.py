N = input()
S = input()

r = 0
g = 0
b = 0

for char in S:
    if char == 'R':
        r += 1
    elif char == 'G':
        g += 1
    elif char == 'B':
        b += 1

print((r % 2 + b % 2 + g % 2))