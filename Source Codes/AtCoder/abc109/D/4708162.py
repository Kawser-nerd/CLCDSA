h, w = [int(item) for item in input().split()]

lists = [[0] * w] * h

for i in range(h):
  lists[i] = [int(item) for item in input().split()]

count = 0
operations = ""
for i, l in enumerate(lists):
  for j, a in enumerate(l):
    if j == w-1:
      break
    if a%2 == 1:
      lists[i][j] -= 1
      lists[i][j+1] += 1
      count += 1
      operations += str(i+1,) + " " + str(j+1) + " " + str(i+1) + " " + str(j+2) + "\n"

for i in range(h):
  if i == h-1:
    break
  if lists[i][w-1] % 2 == 1:
    lists[i][j] -= 1
    lists[i+1][j] += 1
    count += 1
    # print(i+1, j+1, i+2, j+1)
    operations += str(i+1,) + " " + str(j+1) + " " + str(i+2) + " " + str(j+1) + "\n"

print(count)
print(operations)