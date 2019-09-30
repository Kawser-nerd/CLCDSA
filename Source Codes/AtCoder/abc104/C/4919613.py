d, g = map(int, input().split())
p = [list(map(int, input().split())) for _ in range(d)]

ans = 1000
for i in range(1 << d):
  score = 0
  num = 0
  remain_max = -1
  for j in range(d):
    if i >> j & 1:
      score += p[j][0] * 100 * (j + 1) + p[j][1]
      num += p[j][0]
    else:
      remain_max = j
  if score < g:
    remain = 100 * (remain_max + 1)
    need = -(-(g - score) // remain)
    if need >= p[remain_max][0]:
      continue
    num += need
  ans = min(ans, num)
print(ans)