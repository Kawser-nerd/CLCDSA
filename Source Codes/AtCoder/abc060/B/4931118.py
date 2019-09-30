a,b,c=map(int,input().split())
list=[0]*100
for i in range(a*b):
  list[a*i%b] += 1
if list[c] >= 1:
  print('YES')
else:
  print('NO')