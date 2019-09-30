h,w = map(int,input().split())
hw = [list(input()) for j in range(h)]
tf = [True for i in range(w)]
ans = []
for i in hw:
  if i.count(".") != w:
    ans.append(i)
  for j in range(len(i)):
    if i[j]=="#":
      tf[j] = False
for i in range(len(ans)):
  for j in range(len(tf)):
    if not tf[j]:
      print(ans[i][j],end='')
  print('')