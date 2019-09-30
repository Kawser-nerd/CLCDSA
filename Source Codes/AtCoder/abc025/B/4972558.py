N, A, B = map(int, input().split())
sd = [input().split() for i in range(N)]
#print(sd)

pos = 0
for i in range(N):
  step = min(max(int(sd[i][1]), A), B)
  if sd[i][0] == 'West':
    step *= -1
  pos += step

if pos == 0:
  print(pos)
else:
  dest = 'East' if pos > 0 else 'West'
  print("{0} {1}".format(dest, abs(pos)))