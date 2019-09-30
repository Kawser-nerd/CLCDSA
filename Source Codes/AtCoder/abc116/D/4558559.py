n, k = [int(item) for item in input().split()]
sushi = [[int(item) for item in input().split()] for _ in range(n)]
sushi.sort(key=lambda x: x[1], reverse = True)

kind = set()
changeable = []

points = 0
for i in range(k):
  points += sushi[i][1]
  if sushi[i][0] in kind:
    changeable.append(sushi[i][1])
  else:
    kind.add(sushi[i][0])

points += len(kind)**2
ans = points

for i in range(k, n):
  if not changeable:
    break
  if sushi[i][0] not in kind:
    kind.add(sushi[i][0])
    points += sushi[i][1] - (len(kind)-1)**2 + len(kind)**2 - changeable.pop()
    ans = max(ans, points)

print(ans)