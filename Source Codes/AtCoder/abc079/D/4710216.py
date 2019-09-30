H, W = map(int, input().split())
cost = [list(map(int, input().split())) for _ in range(10)]

for i in range(10):
    for j in range(10):
        for k in range(10):
            cost[j][k] = min(cost[j][k], cost[j][i] + cost[i][k])


sum_cost = 0
for i in range(H):
    num = [int(i) for i in input().split()]
    for n in num:
        if n != -1:
            sum_cost += cost[n][1]

print(sum_cost)