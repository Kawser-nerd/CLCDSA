N, K, Q = map(int, input().split())
a = list(map(int, input().split()))

d = [a]
a = sorted(a)
ans = a[Q-1] - a[0]

while True:
  d_temp = list()
  sub_temp = list()
  for sub in d:
    for c in sub:
      if c != a[0]:
        sub_temp.append(c)
      else:
        d_temp.append(sub_temp)
        sub_temp = list()
    d_temp.append(sub_temp)
    sub_temp = list()

  d = list()
  a = list()
  for sub in d_temp:
    if len(sub) < K:
      continue
    else:
      d.append(sub)
      sub = sorted(sub)
      a.extend(sub[0:len(sub)-K+1])

  a = sorted(a)

  if len(a) < Q:
    break
  else:
    ans = min(ans, a[Q-1] - a[0])

print(ans)