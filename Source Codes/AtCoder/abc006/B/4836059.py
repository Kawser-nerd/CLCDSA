n = int(input())
a = [0, 0, 0, 1]
if n >= 4:
    for i in range(4, n + 1):
        a.append((a[i - 1] + a[i - 2] + a[i - 3]) % 10007)
print(a[n])