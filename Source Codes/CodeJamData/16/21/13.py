from collections import Counter
T = int(input())
for t in range(T):
  c = Counter(input())
  res = {d: 0 for d in range(10)}
  res[8] = c['G']
  for let in 'EIGHT':
    c[let] -= res[8]
  res[3] = c['H']
  for let in 'THREE':
    c[let] -= res[3]
  res[4] = c['U']
  for let in 'FOUR':
    c[let] -= res[4]
  res[2] = c['W']
  for let in 'TWO':
    c[let] -= res[2]
  res[6] = c['X']
  for let in 'SIX':
    c[let] -= res[6]
  res[5] = c['F']
  for let in 'FIVE':
    c[let] -= res[5]
  res[7] = c['V']
  for let in 'SEVEN':
    c[let] -= res[7]
  res[0] = c['Z']
  for let in 'ZERO':
    c[let] -= res[0]
  res[1] = c['O']
  for let in 'ONE':
    c[let] -= res[1]
  res[9] = c['I']
  for let in 'NINE':
    c[let] -= res[9]
  ans = ''.join(str(d)*res[d] for d in range(10))
  print('Case #{}: {}'.format(t+1, ans))

