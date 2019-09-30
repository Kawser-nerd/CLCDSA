N, D, K = map(int, input().split())

days = []
for _ in range(D):
  l, r = map(int, input().split())
  days.append((l, r))

for _ in range(K):
  s, t = map(int, input().split())
  pos = s
  for i, (l, r) in enumerate(days):
    if pos < l or pos > r:
      continue
    if s < t:
      if r < t:
        pos = r
      elif r >= t:
        print(i+1)
        break
    elif s > t:
      if l > t:
        pos = l
      elif l <= t:
        print(i+1)
        break