import copy

A = [[i for i in input()] for j in range(10) ]
Acp = copy.deepcopy(A)
dx = [1,0,-1,0]
dy = [0,1,0,-1]
def search(x,y):
  Acp[x][y] = "x"
  for p in range(4):
        nx = x + dx[p]
        ny = y + dy[p]
        if 0<=nx<10 and 0<=ny<10 and Acp[nx][ny]=="o":
            search(nx,ny)
  return
  
def check():
  for i in range(10):
    for j in range(10):
      if Acp[i][j] == "o":
        return False
  return True

for i in range(10):
  for j in range(10):
    Acp = copy.deepcopy(A)
    search(i,j)
    if check() == True:
      print("YES")
      exit()
print("NO")
#def check_uni(x,y):#??????????????
#  search(x,y)