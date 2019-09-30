s = input()
f = 0
for x in s:
  if f == 0 and x in ['i' , 'I']:
    f += 1
  elif f == 1 and x in ['c', 'C']:
    f += 1
  elif f == 2 and x in ['t', 'T']:
    f += 1
  if f == 3:
    break
if f == 3:
  print("YES")
else:
  print("NO")