h, w = map(int, input().split())

smap = [''.join('.' for _ in range(w+2))]
for _ in range(h):
  smap.append('.' + input().strip() + '.')
smap.append(''.join('.' for _ in range(w+2)))

is_black = True
for i, sline in enumerate(smap):
  for j, s in enumerate(sline):
    if s == '#':
      if smap[i][j-1] == '.' and smap[i][j+1] == '.' and smap[i-1][j] == '.' and smap[i+1][j] == '.':
        is_black = False

if is_black:
  print('Yes')
else:
  print('No')