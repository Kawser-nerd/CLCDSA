n, m = map(int,input().split())
shops = sorted([list(map(int, input().split())) for i in range(n)])
buydrinks = 0
cost = 0

for i in range(n):
    cost += shops[i][0] * shops[i][1]
    buydrinks += shops[i][1]
    if buydrinks >= m:
        cost -= (buydrinks - m) * shops[i][0]
        break

print(cost)