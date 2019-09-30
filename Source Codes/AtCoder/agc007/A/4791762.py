h, w = map(int, input().split())
amap = ['.' * (w + 2)]
for _ in range(h):
  amap.append('.' + input().strip() + '.')
amap.append('.' * (w + 2))

x, y = 1, 1
is_one = True
while x != w or y != h:
  if x == 1 and y == 1 and amap[y][x] != '#':
    break
  c = 0
  if amap[y][x+1] == '#':
    c += 1
  if amap[y][x-1] == '#':
    c += 1
  if amap[y+1][x] == '#':
    c += 1
  if amap[y-1][x] == '#':
    c += 1

  if c != 1:
    break
  else:
    amap[y] = amap[y][:x] + '.' + amap[y][x+1:]
    if amap[y][x+1] == '#':
      x += 1
    elif amap[y+1][x] == '#':
      y += 1
    elif amap[y][x-1] == '#':
      break
    elif amap[y-1][x] == '#':
      break

if x == w or y == h:
  c = 0
  for a in amap:
    c += a.count('#')
  if c == 1:
    print('Possible')
  else:
    print('Impossible')
else:
  print('Impossible')