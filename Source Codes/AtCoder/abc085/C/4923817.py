n,y=map(int,input().split())

flag=1

for i in range(n+1):
  
  for j in range(n+1):
    k=n-i-j
    if i*10000+ j*5000+ 1000*k==y and k>=0:
      print(i,j,n-i-j)
      flag=0
      exit()
if flag:
  print(-1,-1,-1)