n = int(input())
s = input().strip()

is_zoo = False
start = 'SS'
for _s in s[1:-1]:
  if start[-1] == 'S':
    if _s == 'o':
      start += start[-2]
    else:
      start += 'S' if start[-2] == 'W' else 'W'
  else:
    if _s == 'x':
      start += start[-2]
    else:
      start += 'S' if start[-2] == 'W' else 'W'
if (start[-1] == 'S' and s[-1] == 'o' and start[-2] == 'S' and s[0] == 'o') or \
  (start[-1] == 'S' and s[-1] == 'x' and start[-2] == 'W' and s[0] == 'o') or \
  (start[-1] == 'W' and s[-1] == 'o' and start[-2] == 'W' and s[0] == 'x') or \
  (start[-1] == 'W' and s[-1] == 'x' and start[-2] == 'S' and s[0] == 'x'):
  print(start)
  is_zoo = True

start = 'SW'
if not is_zoo:
  for _s in s[1:-1]:
    if start[-1] == 'S':
      if _s == 'o':
        start += start[-2]
      else:
        start += 'S' if start[-2] == 'W' else 'W'
    else:
      if _s == 'x':
        start += start[-2]
      else:
        start += 'S' if start[-2] == 'W' else 'W'
  if (start[-1] == 'S' and s[-1] == 'o' and start[-2] == 'S' and s[0] == 'x') or \
    (start[-1] == 'S' and s[-1] == 'x' and start[-2] == 'W' and s[0] == 'x') or \
    (start[-1] == 'W' and s[-1] == 'o' and start[-2] == 'W' and s[0] == 'o') or \
    (start[-1] == 'W' and s[-1] == 'x' and start[-2] == 'S' and s[0] == 'o'):
    print(start)
    is_zoo = True

start = 'WS'
if not is_zoo:
  for _s in s[1:-1]:
    if start[-1] == 'S':
      if _s == 'o':
        start += start[-2]
      else:
        start += 'S' if start[-2] == 'W' else 'W'
    else:
      if _s == 'x':
        start += start[-2]
      else:
        start += 'S' if start[-2] == 'W' else 'W'
  if (start[-1] == 'S' and s[-1] == 'o' and start[-2] == 'W' and s[0] == 'x') or \
    (start[-1] == 'S' and s[-1] == 'x' and start[-2] == 'S' and s[0] == 'x') or \
    (start[-1] == 'W' and s[-1] == 'o' and start[-2] == 'S' and s[0] == 'o') or \
    (start[-1] == 'W' and s[-1] == 'x' and start[-2] == 'W' and s[0] == 'o'):
    print(start)
    is_zoo = True

start = 'WW'
if not is_zoo:
  for _s in s[1:-1]:
    if start[-1] == 'S':
      if _s == 'o':
        start += start[-2]
      else:
        start += 'S' if start[-2] == 'W' else 'W'
    else:
      if _s == 'x':
        start += start[-2]
      else:
        start += 'S' if start[-2] == 'W' else 'W'
  if (start[-1] == 'S' and s[-1] == 'o' and start[-2] == 'W' and s[0] == 'o') or \
    (start[-1] == 'S' and s[-1] == 'x' and start[-2] == 'S' and s[0] == 'o') or \
    (start[-1] == 'W' and s[-1] == 'o' and start[-2] == 'S' and s[0] == 'x') or \
    (start[-1] == 'W' and s[-1] == 'x' and start[-2] == 'W' and s[0] == 'x'):
    print(start)
    is_zoo = True

if not is_zoo:
  print(-1)