N = int(input())
xy = [list(map(int, input().split())) for i in range(N)]
 
lenList = [[0 for i in range(N)] for j in range(N)]
for i in range(N):
    for j in range (N):
        lenList[i][j] = (xy[i][0] - xy[j][0])**2 + (xy[i][1] - xy[j][1])**2
 
lenList = sum(lenList, [])
print(max(lenList)**0.5)