n, m = list(map(int, input().split()))
l = [list(map(int, input().split())) for i in range(n)]
c = 1001
 
for i in range(n):
  if (l[i][1] > m):
    continue
  elif (l[i][0] < c):
    c = l[i][0]
  else :
    continue

if (c == 1001) :
  print ("TLE")
else :
  print(c)