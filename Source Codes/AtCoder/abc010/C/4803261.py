import math

ren = [int(x) for x in str(input()).split(" ")]

cango = int(ren[4])* int(ren[5])

ou = "NO"
for i in range(int(input())):
  tmp = str(input()).split(" ")
  x =  int(tmp[0])
  y = int(tmp[1])
  tofrom = math.sqrt((x - ren[0])*(x - ren[0]) + (y - ren[1])*(y - ren[1]))
  fromto = math.sqrt((ren[2] - x)*(ren[2] - x) + (ren[3] - y)*(ren[3] - y))
  if (tofrom + fromto) <= cango:
    ou = "YES"
    break

print(ou)