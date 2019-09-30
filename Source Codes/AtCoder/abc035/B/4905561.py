s = input()
t = int(input())
x = 0
y = 0
unk = 0
for i in range(len(s)):
  if (s[i] == 'L'): x -= 1
  elif (s[i] == 'R'): x += 1
  elif (s[i] == 'U'): y += 1
  elif (s[i] == 'D'): y -= 1 
  else: unk += 1
dist = abs(x) + abs(y)
if (t == 1): dist += unk
else: dist = max(dist - unk, len(s) % 2)
print(dist)