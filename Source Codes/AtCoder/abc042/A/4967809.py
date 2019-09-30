a = list(map(int,input().split()))
b = 0
c = 0
for i in a:
  if i == 7:
    b += 1
  elif i == 5:
    c += 1

if b == 1 and c == 2:
  print("YES")
else:
  print("NO")