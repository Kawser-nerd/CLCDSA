a = int(input())
b = int(input())
c = int(input())
l = [a, b, c]
win = [2, 2, 2]
for i, j in enumerate(l):
  if j==max(l):
    win[i] = 1
  elif j==min(l):
    win[i] = 3
#print(win)
for i in win:
  print(i)