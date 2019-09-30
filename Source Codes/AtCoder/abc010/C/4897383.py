import math
[txa,tya,txb,tyb,t,v] = [int(i) for i in input().split()]
n = int(input())
girls = []
for i in range(n):
  girls.append([int(j) for j in input().split()])
ok = 0
for i in girls:
  x = i[0]
  y = i[1]
  dis = math.sqrt((x - txa)**2 +(y - tya)**2) + math.sqrt((x - txb)**2 +(y - tyb)**2)
  if dis / v <= t:
    ok = 1
    break

if ok == 1:
  print("YES")
else:
  print("NO")