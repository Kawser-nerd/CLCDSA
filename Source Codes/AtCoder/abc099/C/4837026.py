def sum_base10to(n, b):
    if n // b:
        return sum_base10to(n // b, b) + n % b
    return n % b


n = int(input())
i = 0
res = n
for i in range(n + 1):
    cc = sum_base10to(i, 6) + sum_base10to(n - i, 9)
    if cc < res:
        res = cc
print(res)