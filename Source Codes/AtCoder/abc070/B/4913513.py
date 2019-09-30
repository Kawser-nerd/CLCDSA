a, b, c, d = map(int, input().split())
start = sorted([a, c], reverse=True)
end = sorted([b, d])
time = end[0] - start[0]
if time > 0:
  print(time)
else:
  print("0")