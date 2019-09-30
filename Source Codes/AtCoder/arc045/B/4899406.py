n, m = map(int, input().split())
info = [list(map(int, input().split())) for i in range(m)]

class_overlap = [0]*(n+1)
cursum = [0]*(n+1)
ans = []

for i in range(m):
    class_overlap[info[i][0]-1] += 1
    class_overlap[info[i][1]]   -= 1

for i in range(n):
    class_overlap[i+1] += class_overlap[i]

for i in range(n+1):
    if class_overlap[i] == 1:
        class_overlap[i] = 0
    if class_overlap[i] > 1:
        class_overlap[i] = 1

for i in range(n):
    cursum[i+1] = cursum[i] + class_overlap[i]

for i in range(m):
    if cursum[info[i][1]] - cursum[info[i][0]-1] == info[i][1] - info[i][0] + 1:
      ans.append(i+1)

print(len(ans))
for num in ans:
  print(num)