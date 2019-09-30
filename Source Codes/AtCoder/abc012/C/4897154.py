N = int(input())
All = 2025
n = All - N
for i in range(1, min(n, 9) + 1):
    if n % i == 0 and n // i <= 9:
        print(i, 'x', n // i)