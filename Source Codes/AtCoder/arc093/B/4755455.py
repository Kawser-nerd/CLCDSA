a, b = map(int, input().split())

grid = [['#' for _ in range(100)] for _ in range(50)] \
  + [['.' for _ in range(100)] for _ in range(50)]

for i in range(a-1):
  grid[(i // 50) * 2][(i % 50) * 2] = '.'

for i in range(b-1):
  grid[-((i // 50) * 2) - 1][(i % 50) * 2] = '#'

print(100, 100)
for g in grid:
  print(*g, sep='')