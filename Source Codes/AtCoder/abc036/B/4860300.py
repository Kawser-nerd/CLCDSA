n = int(input())
c = []
for _ in range(n):
    c.append(list(input()))
for i in range(n):
    print("".join(list(reversed("".join(list(map(lambda x: x[i], c)))))))