N = int(input())
S = input()

s = 'b'

if s == S:
  print(0)
else:
  for i in range(100):
    if i % 3 == 0:
      s = 'a' + s + 'c'
    elif i % 3 == 1:
      s = 'c' + s + 'a'
    else:
      s = 'b' + s + 'b'
    if len(s) >= len(S):
      if s == S:
        print(i+1)
      else:
        print(-1)
      break