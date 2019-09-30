S = input()
T = input()
atc = ['a', 't', 'c', 'o', 'd', 'e', 'r', '@']
f = True
for s, t in zip(S, T):
  if s == '@':
    if not t in atc:
      f = False
  elif t == '@':
    if not s in atc:
      f = False
  elif s != t:
    f = False
if f:
  print('You can win')
else:
  print('You will lose')