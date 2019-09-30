s = input()
I = []
C = []
T = []
for j in range(len(s)):
  if s[j] == 'I' or s[j] == 'i':
    I.append(j)
  elif s[j] == 'C' or s[j] == 'c':
    C.append(j)
  elif s[j] == 'T' or s[j] == 't':
    T.append(j)
  else:
    None
flag = False
I.sort()
C.sort()
T.sort()
if len(I) == 0 or len(C) == 0 or len(T) == 0:
  print('NO')
else:
  for i in range(len(I)):
    for j in range(len(C)):
      if I[i] < C[j] < T[len(T)-1]:
        flag = True
        break
      else:
        None
  if flag:
    print('YES')
  else:
    print('NO')