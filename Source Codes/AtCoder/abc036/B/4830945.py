n=int(input())
m=n-1
hoge=[]
for i in range(n):
  hoge.append(input())

for i in range(n):
  for j in range(n):
    print(hoge[m-j][i],end="")
  print("")