n,m=map(int,input().split())
hoge_x=[]
hoge_y=[]
huga_x=[]
huga_y=[]
for i in range(n):
  a,b=map(int,input().split())
  hoge_x.append(a)
  hoge_y.append(b)
  
for j in range(m):
  a,b=map(int,input().split())
  huga_x.append(a)
  huga_y.append(b)

for i in range(n):
  ans_kyori=-1
  ans_index=-1
  for j in range(m):
    kyori=abs(hoge_x[i]-huga_x[j])+abs(hoge_y[i]-huga_y[j])
    if(kyori<ans_kyori or ans_kyori==-1):
      ans_kyori=kyori
      ans_index=j+1
  print(ans_index)