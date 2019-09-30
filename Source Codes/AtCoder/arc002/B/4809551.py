y, m, d = map(int, input().split('/'))

def is_uruu(y):
  if y % 4 == 0:
    if y % 100 == 0:
      if y % 400 == 0:
        return True
      else:
        return False
    else:
      return True
  else:
    return False

while True:
  if y % m == 0 and (y // m) % d == 0:
    break
  d += 1
  if m in [1,3,5,7,8,10,12]:
    if d == 32:
      if m == 12:
        y += 1
        m = 1
        d = 1
      else:
        m += 1
        d = 1
  elif m in [4,6,9,11]:
    if d == 31:
      m += 1
      d = 1
  else:
    if is_uruu(y):
      if d == 30:
        m += 1
        d = 1
    else:
      if d == 29:
        m += 1
        d = 1
print('%4d/%02d/%02d' % (y, m, d))