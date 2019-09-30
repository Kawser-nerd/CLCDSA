n,d,k = map(int,input().split())
info_side = [list(map(int,input().split())) for i in range(d)]
tribe = [list(map(int,input().split())) for i in range(k)]

for i in range(k):
  for j in range(d):
    if info_side[j][0] <= tribe[i][0] <= info_side[j][1]:
      if tribe[i][0] < tribe[i][1]:
        tribe[i][0] = info_side[j][1]
        if tribe[i][0] >= tribe[i][1]:
          print(j+1)
          break
      else:
        tribe[i][0] = info_side[j][0]
        if tribe[i][0] <= tribe[i][1]:
          print(j+1)
          break