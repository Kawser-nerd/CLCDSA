n = int(input())
ans = 2025 - n

for i in range(1, 10):
    if ans % i == 0 and 1 <= ans // i <= 9:
        print(i, "x", ans // i)