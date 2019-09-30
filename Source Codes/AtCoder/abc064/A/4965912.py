r,g,b=map(str,input().split())
s=r+g+b
s=int(s)
if s%4==0:
  print('YES')
else:
  print('NO')