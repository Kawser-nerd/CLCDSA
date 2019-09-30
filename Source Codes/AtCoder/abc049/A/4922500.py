from sys import stdin

p = stdin.readline().rstrip()
if p in {'a', 'e', 'i', 'o', 'u'}:
  print('vowel')
else:
  print('consonant')