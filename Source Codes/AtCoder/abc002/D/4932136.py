n, m = map(int, input().split())
rel = [[i + 1] for i in range(n)]

for i in range(m):
  x, y = map(int, input().split())
  rel[x - 1].append(y)
  rel[y - 1].append(x)

ans = 1
for i in range(1, 1 << n):
  group = []
  for j in range(n):
    if i >> j & 1:
      group.append(j + 1)
  if all(all(k in rel[j - 1] for j in group) for k in group):
    ans = max(ans, len(group))
print(ans)