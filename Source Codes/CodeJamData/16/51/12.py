SUBMIT = 0
REQUEST = 1

_T = int(raw_input())
for _t in range(1, _T+1):

  S = raw_input()

  Q = []
  res = 0
  for i in range(len(S)):
    if len(Q) == 0:
      action = REQUEST
    elif S[i] == Q[-1]:
      action = SUBMIT
    elif len(Q) >= len(S) - i: # Submit or request?
      action = SUBMIT
    else:
      action = REQUEST
    if action == REQUEST:
      Q.append(S[i])
    else:
      res += 10 if S[i] == Q[-1] else 5
      Q.pop()

  print 'Case #{}: {}'.format(_t, res)
