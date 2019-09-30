s = input().strip()
t = input().strip()

if len(s) < len(t):
  print('UNRESTORABLE')
else:
  cands = []
  for i in range(len(s) - len(t) + 1):
    is_match = True
    for _s, _t in zip(s[i:i+len(t)], t):
      if _s != '?':
        if _s != _t:
          is_match = False
          break
    if is_match:
      cand = s.replace('?', 'a')
      cand = cand[:i] + t + cand[i+len(t):]
      cands.append(cand)
  if cands:
    print(list(sorted(cands))[0])
  else:
    print('UNRESTORABLE')