n = int(input())
a = []
for i in range(n):
  x,y = map(int,input().split())
  a.append([x,y])
l = sorted(a,key=lambda x: -x[0])
r = sorted(a,key=lambda x: x[1])
left = 0
hi = 0
mi = 0
for i in range(n):
  hi += l[i][0]
  left = max(left,(hi-mi)*2)
  mi += r[i][1]
  left = max(left,(hi-mi)*2)
right = 0
hi = 0
mi = 0
for i in range(n):
  mi += r[i][1]
  right = max(right,(hi-mi)*2)
  hi += l[i][0]
  right = max(right,(hi-mi)*2)
print(max(right,left))