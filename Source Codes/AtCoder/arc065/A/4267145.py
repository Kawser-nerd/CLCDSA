s = input()
t = s[::-1]
i = 0
k = len(s)
while i <= k-5:
  if k-i >= 7:
    if t[i] != 'r':
      if t[i:i+5] == 'maerd':
        i += 5
      elif t[i:i+5] == 'esare':
        i += 5
      else:
        i = k+1
    else:
      if t[i:i+6] == 'resare':
        i += 6
      elif t[i:i+7] == 'remaerd':
        i += 7
      else:
        i = k+1
  elif k-i == 6:
    if t[i:i+6] == 'resare':
      i = k
    else:
      i = k+1
  else:
    if t[i:i+5] == 'esare':
      i = k
    elif t[i:i+5] == 'maerd':
      i = k
    else:
      i = k+1
if i == k:
  print('YES')
else:
  print('NO')