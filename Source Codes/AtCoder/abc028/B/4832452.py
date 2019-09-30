str = list(input())
moji = ['A','B','C','D','E','F']
for i in range(6):
  print(str.count(moji[i]),end='')
  if i < 5:
    print(' ', end='')
print()