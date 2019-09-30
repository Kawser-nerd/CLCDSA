h, w = map(int, input().split())
n = int(input())
alist = list(map(int, input().split()))
cmap = [[-1 for _ in range(w)] for _ in range(h)]
i = 0
for ai, a in enumerate(alist):
  ai += 1
  for _a in range(a):
    if ((i + _a) // w) % 2 == 0:
      cmap[(i + _a) // w][(i + _a) % w] = ai
    else:
      cmap[(i + _a) // w][-((i + _a) % w + 1)] = ai
  i += a

for cm in cmap:
  print(*cm, sep=' ')