N, T = [int(elem) for elem in input().split()]
min_cost = None
min_cost_time = None
for i in range(0, N):
  c, t = [int(elem) for elem in input().split()]
  if t <= T:
    if min_cost is None:
      min_cost = c
      min_cost_time = t
    else:
      if c < min_cost:
        min_cost = c
        min_cost_time = t
if min_cost is None:
  print('TLE')
else:
  print(min_cost)