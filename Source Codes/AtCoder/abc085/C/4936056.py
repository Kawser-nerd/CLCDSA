n,y=map(int,input().split())
x=[]
for i in range(n+1):
  for j in range(n+1-i):
    if y-10000*i-5000*j-1000*(n-i-j)==0:
      x=[i,j,n-i-j] 
      break
    else:
      pass

if x==[]:
  print(-1,-1,-1)
else:
  print(x[0],x[1],x[2])