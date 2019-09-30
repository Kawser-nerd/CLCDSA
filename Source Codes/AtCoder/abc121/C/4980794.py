N, M = map(int, input().split())
shop = []
for i in range(N):
    a, b = map(int, input().split())
    shop.append([a, b])
shop.sort(key=lambda x: x[0])

amount = 0
quantity = 0
for s in shop:
    if quantity + s[1] < M:
        amount += s[0] * s[1]
        quantity += s[1]
    else:
        amount += (M - quantity) * s[0]
        quantity = M
        break

print(amount)