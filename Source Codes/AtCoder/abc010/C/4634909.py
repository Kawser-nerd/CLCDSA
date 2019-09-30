xa, ya, xb, yb, T, V = map(int,input().split())
n = int(input())
flag = False
for i in range(n):
  x,y = map(int, input().split())
  if (((xb-x)**2+(yb-y)**2)**0.5+((x-xa)**2+(y-ya)**2)**0.5)<=(T*V):
    flag = True
if flag:
  print('YES')
else:
  print('NO')