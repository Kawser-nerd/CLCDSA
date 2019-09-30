n,y=map(int,input().split())
flag=False
list=[]
for i in range(n,-1,-1):
  for j in range(0, n-i+1):
    k=n-i-j
    if i*10000+j*5000+k*1000 == y and not(flag):
      flag=True
      list=[i,j,k]
if not(flag):
  print('{} {} {}'.format(-1,-1,-1))
else:
  print('{} {} {}'.format(list[0],list[1],list[2]))