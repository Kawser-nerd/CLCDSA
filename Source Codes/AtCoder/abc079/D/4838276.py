h, w = map(int, input().split())

c = [[] * 10] * 10

a = [[] * w] * h

for y in range(10):
    cx = list(map(int, input().split()))
    c[y] = cx


for z in range(10):
    for y in range(10):
        for x in range(10):
            if c[y][x] > c[y][z] + c[z][x]:
                c[y][x] = c[y][z] + c[z][x]

for y in range(h):
    ax = list(map(int, input().split()))
    a[y] = ax

e = 0
for y in range(h):
    for x in range(w):
        if a[y][x] != -1 and a[y][x] != 1:
            i = a[y][x]
            e += c[i][1]
print(e)