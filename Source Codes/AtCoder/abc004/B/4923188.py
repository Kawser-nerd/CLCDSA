hoge=[]
for i in range(4):
  hoge.append(list(map(str,input().split())))
for i in range(4):
  for j in range(4):
    print(hoge[3-i][3-j],end=" ")
  print("")