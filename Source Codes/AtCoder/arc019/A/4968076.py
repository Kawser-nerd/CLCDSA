s = list(input())

res = ''
for i in s:
  if i == 'I':
    res += '1'
  elif i == 'D' or i == 'O':
    res += '0'
  elif i == 'B':
    res += '8'
  elif i == 'Z':
    res += '2'
  elif i == 'S':
    res += '5'
  else:
    res += i

print(res)