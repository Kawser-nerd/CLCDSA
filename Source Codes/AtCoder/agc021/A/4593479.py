N = input()
flag = True
if N[0] == '1':
  for i in range(1,len(N)):
    if N[i] != '9':
      flag = False
      break
  if not flag:
    print(9*(len(N)-1))
  else:
    print(1+9*(len(N)-1))
else:
  for i in range(1,len(N)):
    if N[i] != '9':
      flag = False
      break
  if not flag:
    print(9*(len(N)-1)+int(N[0])-1)
  else:
    print(9*(len(N)-1)+int(N[0]))