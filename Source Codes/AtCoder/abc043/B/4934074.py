x = input()
s = []
for i in x:
  if i == 'B':
    if len(s) == 0:
      continue
    del s[-1]
  else:
    s.append(i)
print(''.join(s))