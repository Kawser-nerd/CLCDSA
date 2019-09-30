s = input().strip()

gc, pc = 0, 0
wc, lc = 0, 0
for _s in s:
  if _s == 'g':
    if pc + 1 <= gc:
      pc += 1
      wc += 1
    else:
      gc += 1
  else:
    if pc + 1 <= gc:
      pc += 1
    else:
      gc += 1
      lc += 1
print(wc - lc)