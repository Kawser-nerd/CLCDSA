n = int(input())
li = [input() for _ in range(n)]
march = [0, 0, 0, 0, 0]
for i in range(n):
  if li[i][0] == 'M': march[0] += 1
  if li[i][0] == 'A': march[1] += 1
  if li[i][0] == 'R': march[2] += 1
  if li[i][0] == 'C': march[3] += 1
  if li[i][0] == 'H': march[4] += 1
cnt = 0
for j in range(3):
  for k in range(j+1, 4):
    for l in range(k+1, 5):
      cnt += march[j] * march[k] * march[l]

print(cnt)