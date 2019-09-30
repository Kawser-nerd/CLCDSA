H, W = map(int, input().split())

a = []
for i in range(H):
    a.append(list(map(int, input().split())))

onestroke = []

for i in range(H):
    for j in range(W):
        if i%2==0:
            onestroke.append([i, j])
        else:
            onestroke.append([i, W-j-1])

list = []
N = 0

for i in range(H*W-1):
    if a[onestroke[i][0]][onestroke[i][1]]%2!=0:
        list.append([onestroke[i][0]+1, onestroke[i][1]+1, onestroke[i+1][0]+1, onestroke[i+1][1]+1])
        N += 1
        a[onestroke[i+1][0]][onestroke[i+1][1]] += 1

print(N)
for i in range(N):
    print(list[i][0], list[i][1], list[i][2], list[i][3])