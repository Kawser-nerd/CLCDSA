import math
N = int(input())
points = [list(map(int, input().split())) for _ in range(N)]
max = 0
for i in range(N-1):
    for j in range(i+1, N):
        dist = (points[i][0]-points[j][0])**2 + (points[i][1]-points[j][1])**2
        if dist > max: max = dist
print(math.sqrt(max))