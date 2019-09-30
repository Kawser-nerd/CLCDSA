S = input()
g = 0
p = 0
win = 0
lose = 0
for s in S:
  if(s == "g"):
    if(p < g):
      p += 1
      win += 1
    elif(p == g):
      g += 1
  else:
    if(p < g):
      p += 1
    elif(p == g):
      g += 1
      lose += 1
print(win-lose)