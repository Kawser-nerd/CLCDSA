N = int(input())
n = 2025 - N
for a in range(1, 10):
    for b in range(1, 10):
        if a * b == n:
            print(a, 'x', b)