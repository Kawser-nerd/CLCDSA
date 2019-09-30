n, lower, upper = map(int, input().split())
res = 0

for i in range(n):
  step = input().split()
  if step[0] == "West":
    offset = -1
  elif step[0] == "East":
    offset = 1

  if int(step[1]) < lower:
    res += lower * offset
  elif int(step[1]) > upper:
    res += upper * offset
  else:
    res += int(step[1]) * offset

if res == 0:
  print(0)
elif res > 1:
  print("East %s" % str(res))
else:
  print("West %s" % str(abs(res)))