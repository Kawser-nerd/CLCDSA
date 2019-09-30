N = int(input())
As = list(map(int, input().split()))
As.insert(0, 0)
As.append(0)

total = 0
costs = []
for i in range(1, N+1):
    total += abs(As[i] - As[i-1])
    x1 = As[i] - As[i-1]
    x2 = As[i+1] - As[i-1]
    if x1 * x2 >= 0 and abs(x1) <= abs(x2):
        costs.append(0)
    elif x1 * x2 >= 0 and abs(x1) > abs(x2):
        costs.append(2 * abs(x2 - x1))
    elif x1 * x2 < 0:
        costs.append(2 * abs(x1))
total += abs(As[N+1] - As[N])

for i in range(N):
    print(total - costs[i])