import sys
n,m = map(int, input().split())
a = []
b = []
for i in range(n):
  a.append(list(input()))
  
for i in range(m):
  b.append(list(input()))


#

  
  
for i in range(n-m+1):
  for j in range(n-m+1):
    flag = True
    for x in range(m):
      for y in range(m):
        if b[x][y] !=  a[i+x][j+y]:
          flag = False
          break
      if not flag:
        break
    else:
      print("Yes")
      sys.exit()
     
    

print("No")