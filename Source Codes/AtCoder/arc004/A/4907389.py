import math
N = int(input())
c = [list(map(int, input().split())) for i in range(N)]
max_lengh = 0
for i in range(N):
    for j in range(i, N):
        max_lengh = max(max_lengh, (c[i][0] - c[j][0]) ** 2 + (c[i][1] - c[j][1]) ** 2)
print("{:.9f}".format(math.sqrt(max_lengh)))