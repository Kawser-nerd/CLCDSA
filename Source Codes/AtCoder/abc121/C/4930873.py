N, M = map(int, input().split())
shops = sorted([list(map(int, input().split())) for i in range(N)])
drink = 0
cost = 0

for i in range(N):
    cost += shops[i][0]*shops[i][1]
    drink += shops[i][1]
    if drink >= M:
        cost -= (drink -M) * shops[i][0]
        break
        
print(cost)