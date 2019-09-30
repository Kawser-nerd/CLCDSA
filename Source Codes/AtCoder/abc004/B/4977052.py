L = [[i for i in input().split()] for _ in range(4)]
for Li in reversed(L):
  s = ''
  for i in reversed(Li):
    s = s + i + ' '
  print(s[:-1])