n = int(input())
xu = [input().split() for i in range(n)]
for i in xu:
    i[0] = float(i[0])

for i in xu:
    if i[1] == 'BTC':
        i[0] *= 380000

print(sum(xu[i][0] for i in range(n)))