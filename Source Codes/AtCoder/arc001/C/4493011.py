M = [list(input()) for i in range(8)]
 
def check(M,y,x):
  for i in range(1,8):
    yl = [y  ,y  ,y-i,y+i,y-i,y-i,y+i,y+i]
    xl = [x-i,x+i,x  ,  x,x-i,x+i,x-i,x+i]
    
    for i2, j2 in zip(yl,xl): 
      if 0<=i2 <=7 and 0<=j2<=7 and M[i2][j2] == "Q":
        return 0
  return 1
 
def dfs(M,q):
  if q == 0:
    for m in M:
      print("".join(m))
    exit()
 
  for y in range(8):
    for x in range(8):
      if M[y][x] != "Q" and check(M,y,x) == 1:
        M[y][x] = "Q" #Q?????
        dfs(M,q-1)
        M[y][x] = "." #??????
 
        
for y in range(8):
  for x in range(8):
    if M[y][x] == "Q" and check(M,y,x) == 0:
      print("No Answer")
      exit()
 
dfs(M,5)
print("No Answer")