import numpy as np

n,m=map(int,input().split())

hoge=[]
huga=[]
hago=[]
h=0
w=0
for i in range(n):
  hoge.append(list(input()))

for i in range(n):
  if(hoge[i].count("#")!=0):
    h+=1
    huga.append(hoge[i])
    
hoge=np.array(huga).T.tolist()

for i in range(m):
  if(hoge[i].count("#")!=0):
    w+=1
    hago.append(hoge[i])
    
hago=np.array(hago).T.tolist()
    
for i in range(h):
  for j in range(w):
    print(hago[i][j],end="")
  print("")