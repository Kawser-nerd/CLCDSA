S=input()
while True:
  if S=='':
    print('YES')
    break
  else:
    a = S[-5:] in ('dream', 'erase')
    b = S[-6:] in ('eraser')
    c = S[-7:] in ('dreamer')
    if not (a or b or c):
      print('NO')
      break
    elif a:
      S = S[:-5]
    elif b:
      S = S[:-6]
    elif c:
      S = S[:-7]