ls = []
for i in range(3):
  ls.append(int(input()))
rank = {}
for i in range(len(ls)):
  if ls[i] == max(ls):
    rank[i] = 1
  elif ls[i] == min(ls):
    rank[i] = 3
  else:
    rank[i] = 2
for i in range(3):
  print(rank[i])