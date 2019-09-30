N, L = [int(_) for _ in input().split()]

b = [input().split("|") for i in range(L)]

x = input().find("o") // 2 + 1

for y in range(L - 1, -1, -1):
    if b[y][x - 1] == "-":
        x -= 1
    elif b[y][x] == "-":
        x += 1

print(x)