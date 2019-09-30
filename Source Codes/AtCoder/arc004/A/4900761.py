N=int(input())
point=[list(map(int,input().split())) for i in range(N)]

distance=0

for i in range(N):
    for j in range(N):
        distance=max(distance, ((point[i][0]-point[j][0])**2 + (point[i][1]-point[j][1])**2)**0.5)

print(distance)