n = int(input())
words = input().split()
ans = []
for word in words:
  w = list(word.lower())
  temp = ''
  for j in range(len(w)):
    if w[j] == 'b' or w[j] == 'c':
      temp += '1'
    elif w[j] == 'd' or w[j] == 'w':
      temp += '2'
    elif w[j] == 't' or w[j] == 'j':
      temp += '3'
    elif w[j] == 'f' or w[j] == 'q':
      temp += '4'
    elif w[j] == 'l' or w[j] == 'v':
      temp += '5'
    elif w[j] == 's' or w[j] == 'x':
      temp += '6'
    elif w[j] == 'p' or w[j] == 'm':
      temp += '7'
    elif w[j] == 'h' or w[j] == 'k':
      temp += '8'
    elif w[j] == 'n' or w[j] == 'g':
      temp += '9'
    elif w[j] == 'z' or w[j] == 'r':
      temp += '0'

  if not temp == '':
    ans.append(temp)
print(' '.join(ans))