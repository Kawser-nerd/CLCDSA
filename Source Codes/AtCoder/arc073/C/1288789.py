N = int(input())
balls = sorted(tuple(sorted(map(int,input().split()))) for i in range(N))

# Rmin=MIN, Bmax=MAX
maxmin = balls[-1][0]
minmin = balls[0][0]
maxmax = max(b[1] for b in balls)
minmax = min(b[1] for b in balls)

v1 = (maxmin-minmin)*(maxmax-minmax)

# Rmin=MIN, Rmax=MAX
best = float('inf')
cur_max = maxmin
for b in balls:
  if b[0] > minmax:
    best = min(best, cur_max-minmax)
    break
  best = min(best, cur_max-b[0])
  cur_max = max(cur_max, b[1])
 
v2 = (maxmax-minmin)*best

print(min(v1,v2))