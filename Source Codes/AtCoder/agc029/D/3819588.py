from operator import itemgetter
h, w, n = map(int, input().split())
coord = [list(map(int, input().split())) for i in range(n)]

co_sort = sorted(sorted(coord), key = itemgetter(1))
c = h
r = 0
for co in co_sort:
  if co[0] - 1- r >= co[1]:
    c = min(c, co[0]-1)
  elif co[0] - r == co[1]:
    r += 1

print(c)