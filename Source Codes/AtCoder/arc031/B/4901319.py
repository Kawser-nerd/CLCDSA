isl = [['#' for i in range(12)] for j in range(12)]
around = [[-1,0],[0,-1],[0,1],[1,0]]
ans = 0

def search(l,x,y,c):
    l[x][y] = c
    for i in around:
        if l[x+i[0]][y+i[1]] == 0:
            search(l,x+i[0],y+i[1],c)

for i in range(1,11):
    S = list(input())
    for j in range(1,11):
        if S[j-1] == 'o':
            isl[i][j] = 0
        else:
            isl[i][j] = -1

count = 1
for i in range(12):
    for j in range(12):
        if isl[i][j] == 0:
            search(isl,i,j,count)
            count += 1

for i in range(12):
    for j in range(12):
        if isl[i][j] == -1:
            if all(any((isl[i+l[0]][j+l[1]] == k for l in around)) for k in range(1,count)):
                ans = 'YES'
                break
    else:
        ans = 'NO'
        continue
    break

print(ans)