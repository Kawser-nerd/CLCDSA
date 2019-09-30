N, C = map(int, input().split())
data = [list(map(int, input().split())) for _ in range(C)]

color = [[0] * C for _ in range(3)]

for i in range(N):
    c = input().split()
    for j in range(N):
        color[(i+j)%3][int(c[j])-1] += 1

sumcolor = [[0] * C for _ in range(3)]


for i in range(3):
    for j in range(C):
        for c in range(C):
            sumcolor[i][j] += color[i][c] * data[c][j]

answer = 10 ** 18
for i in range(C):
    for j in range(C):
        for k in range(C):
            if i != j and i != k and j != k:
                answer = min(answer, sumcolor[0][i]+sumcolor[1][j]+sumcolor[2][k])


print(answer)