n, h = map(int, input().split())
a, b, c, d, e = map(int, input().split())

def get_min_cost(normal):
    cheap = max((e * (n - normal) - b * normal - h) // (d + e) + 1, 0)
    if normal + cheap <= n:
        return a * normal + c * cheap
    else:
        return 10 ** 12

min_cost = 10 ** 12

for i in range(n + 1):
    min_cost = min(get_min_cost(i), min_cost)

print(min_cost)