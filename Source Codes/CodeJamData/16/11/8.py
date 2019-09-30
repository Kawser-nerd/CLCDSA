_T = int(raw_input())
for _t in range(1, _T+1):

  S = raw_input()

  res = ''
  for c in S:
    tmp1 = c + res
    tmp2 = res + c
    if tmp1 > tmp2: res = tmp1
    else: res = tmp2

  print 'Case #{}: {}'.format(_t, res)
