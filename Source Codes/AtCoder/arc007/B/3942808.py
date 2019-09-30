N, M = map(int, input().split())
data = list(range((N + 1)))

for _ in range(M):
    item = int(input())
    index = data.index(item)
    data[0], data[index] = data[index], data[0]

for item in data[1:]:
    print(item)