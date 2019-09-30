N, M = map(int, input().split())
city = []
for i in range(M):
  P, Y = map(int, input().split())
  city.append([P, Y, i])
id = [''] * M

city.sort(key = lambda x: (x[0], x[1]))
prev_P = 0
count = 0
for i in city:
  if prev_P == i[0]:
    count += 1
  else:
    count = 1
  id[i[2]] = str(i[0]).zfill(6) + str(count).zfill(6)
  prev_P = i[0]

for i in range(M):
  print(id[i])