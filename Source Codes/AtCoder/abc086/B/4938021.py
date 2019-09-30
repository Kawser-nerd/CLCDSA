a,b=map(int,input().split())
num=int(str(a)+str(b))
flag=False
for i in range(1000):
  if i**2 == num:
    flag=True
if flag:
  print('Yes')
else:
  print('No')