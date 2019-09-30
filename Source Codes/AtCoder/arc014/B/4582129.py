n = int(input())
w = [input() for _ in range(n)]
for i in range(1,n):
  if w[i-1][-1] != w[i][0] or w[i] in w[:i]:
    b = i
    break
else:
  print("DRAW")
  exit()
if b%2:
  print("WIN")
else:
  print("LOSE")