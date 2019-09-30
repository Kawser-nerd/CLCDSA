n = int(input())

items = []

for i in range(n):
    items.append(tuple(map(int, input().split())))

enogu = [0] * (10 ** 6 + 2)

for i in range(n):
    a, b = items[i]
    enogu[a] += 1
    enogu[b + 1] -= 1

for i in range(len(enogu) - 1):
    enogu[i + 1] += enogu[i]

print(max(enogu))