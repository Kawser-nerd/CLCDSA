k,n = map(int,input().split())
a = []
for i in range(n):
  x,y =input().split()
  a.append([x,y])
for i in range(3**k):
  b = []
  while i:
    c = i %3
    b.append(c+1)
    i = (i-c)//3
  while len(b) < k:
    b.append(1)
  ans = [[None] for i in range(k)]
  flag = 0
  for j in range(n):
    kazu = a[j][0]
    mozi = a[j][1]
    for l in kazu:
      l = int(l)-1
      kon = mozi[:b[l]]
      mozi = mozi[b[l]:]
      if ans[l] == [None]:
        ans[l] = kon
      else:
        if ans[l] != kon:
          flag = 1
          break
    if mozi != "":
      flag = 1
      break
  if flag == 0:
    for j in range(k):
      print(ans[j])
    exit()