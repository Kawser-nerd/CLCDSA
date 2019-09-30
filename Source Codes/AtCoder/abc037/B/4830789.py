n,q=map(int,input().split())
hoge=[0]*n
for i in range(q):
  a,b,c=map(int,input().split())
  for i in range(b-a+1):
    hoge[a+i-1]=c

for i in range(n):
  print(hoge[i])