H, W = map(int, input().split())
bd = []

for i in range(H):
    bd.append(input())

x = set()
y = set()
for i in range(H):
    for j in range(W):
        if bd[i][j] == '#':
            x.add(j)
            y.add(i)

for i in y:
    for j in x:
        print(bd[i][j], end='')
    print()