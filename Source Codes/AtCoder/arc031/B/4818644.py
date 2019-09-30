# ARC031B
import copy
field = []
for p in range(10):
    field.append([str(x) for x in str(input())])
 
temp = copy.deepcopy(field)
 
dx = [1,0,-1,0]
dy = [0,1,0,-1]
 
 
def dfs(x,y):
    temp[x][y] = "x"
    for p in range(4):
        nx = x + dx[p]
        ny = y + dy[p]
        if 0<=nx<10 and 0<=ny<10 and temp[nx][ny]=="o":
            dfs(nx,ny)
    return
 
 
def check():
    for p in range(10):
        for q in range(10):
            if temp[p][q] == "o":
                return False
    return True
 
 
for p in range(10):
    for q in range(10):
        temp = copy.deepcopy(field)
        dfs(p,q)
        if check() == True:
            print("YES")
            exit()
print("NO")