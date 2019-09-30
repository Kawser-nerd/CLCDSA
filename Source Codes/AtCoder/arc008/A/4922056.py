n = int(input())

q, mod = divmod(n, 10)
print(q * 100 + min(100, 15 * mod))