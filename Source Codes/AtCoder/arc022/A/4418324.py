s = input().lower()
b = 0
for i in s:
  if i == "i" and b == 0:
    b = 1
  if i == "c" and b == 1:
    b = 2
  if i == "t" and b == 2:
    b = 3
if b == 3:
  print("YES")
else:
  print("NO")