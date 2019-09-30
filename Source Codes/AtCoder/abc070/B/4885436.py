a, b, c, d = map(int, input().split())

time = min(b, d) - max(a, c)
if time >= 0:
  print(time)
else:
  print("0")