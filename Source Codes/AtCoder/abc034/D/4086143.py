n,k=map(int,input().split())
g=[]
for _ in range(n):
  w,p=map(int,input().split())
  g.append([w,p/100*w])
i,j=0,1
b=j
for _ in range(100):
  if sum(sorted(map(lambda x:x[1]-j*x[0],g))[-k:])<0:
    b=j
    j=(j+i)/2
  else:
    t=j
    j=(b+j)/2
    i=t
print(j*100)